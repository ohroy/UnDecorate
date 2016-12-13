## 功能
这个小工具能将c++导出的函数格式转成友好的定义。
是我在制作干净云的过程中做的一个小工具，用来分析百度云管家的导出函数。
## 示例
```cmd
UnDecorate.exe   ?apiname@@YA_NEEPAD@Z   
```
将会输出
```shell
bool __cdecl apiname(unsigned char,unsigned char,char *)
```