#hbase RPC消息序列化反序列化库的编译生成。


cmake_minimum_required(VERSION 2.8)
project(dynamictest)


SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
#SET(CMAKE_C_VISIBILITY_PRESET hidden)
#SET(CMAKE_CXX_VISIBILITY_PRESET hidden)
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
#SET(CMAKE_BUILD_TYPE Debug)


SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")
SET(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

SET(LINK_DIRECTORIES,"${PROJECT_BINARY_DIR}/lib")

add_library(mystatic STATIC staticf/static.cpp)
add_library(dynamic1 SHARED dynamic1/dynamic.cpp)
add_library(dynamic2 SHARED dynamic2/dynamic.cpp)
target_link_libraries(dynamic1 "-Wl,--whole-archive" mystatic "-Wl,--no-whole-archive")
target_link_libraries(dynamic2  "-Wl,--whole-archive" mystatic "-Wl,--no-whole-archive")

add_executable(test main.cpp)
target_link_libraries(test dl)



#add_library(hbaseproto SHARED ${DIR_SRCS} ${HBASE_PROTO_SRC} ${CJSON})
#target_link_libraries(hbaseproto protobuf)