# exercise
编程过程中，一些疑问或不确定东西的验证。

dynamiclinkstatic：  动态库链接静态库的方式，以及多个动态库链接同一个静态库时，静态库中全局变量是否共享的问题。

TODO:
1、静态库中全局变量与可执行程序中全局变量同名时的状况
2、动态库中全局变量与可执行程序中全局变量同名时的状况
  2.1 动态库中全局变量被覆盖时，如何强制使用本地变量。
3、多个动态库拥有同名全局变量的情况
4、被多个动态库依赖的动态库里的全局变量是否共享