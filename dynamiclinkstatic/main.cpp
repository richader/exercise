#include <stdio.h>
#include <dlfcn.h>
#include <dirent.h>
#include <unistd.h>

#include <map>
#include <string>
#include <iostream>

using namespace std;

const static char* prefix = "libdynamic";
const static char* path = "../lib/";



typedef  void* HANDLE;
typedef void (*pfunc)();

pfunc sets[10];
pfunc prts[10];

int main(int argc, char const *argv[])
{

    std::map<std::string,HANDLE> libs;

	struct dirent* p_dirent;
    DIR* p_dir = opendir(path);
    int nums=0;
    if(p_dir != NULL){
        while((p_dirent=readdir(p_dir))!=NULL){
            std::string file_name = p_dirent->d_name;
            if(file_name.find(prefix) == std::string::npos){
                continue;
            }
            sleep(1);
            file_name =path+ file_name;
            cout << "open:"<<file_name <<endl;
            void* so_handle = dlopen(file_name.c_str(),RTLD_NOW);
            if(so_handle){
                sets[nums]=(pfunc)dlsym(so_handle,"SetMyValue");
                if(sets[nums] ==NULL){
                    cout<<"get SetMyValue error:"<<dlerror()<<endl;
                }
                prts[nums]=(pfunc)dlsym(so_handle,"PrintValue");
                if(prts[nums] ==NULL){
                    cout<<"get PrintValue error:"<<dlerror()<<endl;
                }

                nums++;
                cout<< "  success!"<<endl;
            }else{
            	cout<< "  failed:"<<dlerror()<<endl;
            }
        }
        closedir(p_dir);
    }

    for(int i=0;i<nums;++i){
        sets[i]();
        prts[i]();
    }
    for(int i=0;i<nums;++i){
        prts[i]();
    }
	return 0;
}