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


## 延伸

#### 调用协议的编码

| Code | Exported? | Calling Convention |
| ---- | --------- | ------------------ |
| `A`  | No        | __cdecl            |
| `B`  | Yes       | __cdecl            |
| `C`  | No        | __pascal __fortran |
| `D`  | Yes       | __pascal           |
| `E`  | No        | __thiscall         |
| `F`  | Yes       | __thiscall         |
| `G`  | No        | __stdcall          |
| `H`  | Yes       | __stdcall          |
| `I`  | No        | __fastcall         |
| `J`  | Yes       | __fastcall         |
| `K`  | No        | *none*             |
| `L`  | Yes       | *none*             |
| `M`  | No        | __clrcall          |





### 数据类型的编码表示

这里所说的类型，包括数据类型、函数指针的类型、函数模板、类模板等不需要分配内存空间的一些概念属性。类型是数据对象与函数这两类实体的属性。

| 编码   | 不带下划线(_)的含义                              | 前置下划线(_)的含义                  |
| ---- | ---------------------------------------- | ---------------------------- |
| ?    | *用于表示模板*                                 |                              |
| $    | *用于表示模板*                                 | __w64 *(prefix)*             |
| 0-9  | *Back reference*即用于重复出现的类型或名字的简写         |                              |
| A    | *Type modifier (reference)*              |                              |
| B    | *Type modifier (volatile reference)*     |                              |
| C    | signed char                              |                              |
| D    | char                                     | __int8                       |
| E    | unsigned char                            | unsigned __int8              |
| F    | short                                    | __int16                      |
| G    | unsigned short                           | unsigned __int16             |
| H    | int                                      | __int32                      |
| I    | unsigned int                             | unsigned __int32             |
| J    | long                                     | __int64                      |
| K    | unsigned long                            | unsigned __int64             |
| L    |                                          | __int128                     |
| M    | float                                    | unsigned __int128            |
| N    | double                                   | bool                         |
| O    | long double                              | *Array*                      |
| P    | *Type modifier (pointer)*                |                              |
| Q    | *Type modifier (const pointer)*          |                              |
| R    | *Type modifier (volatile pointer)*       |                              |
| S    | *Type modifier (const volatile pointer)* |                              |
| T    | *union*                                  |                              |
| U    | *struct*                                 |                              |
| V    | *class*                                  |                              |
| W    | *enum*                                   | wchar_t                      |
| X    | void, *Complex Type (coclass)*           | *Complex Type (coclass)*     |
| Y    | *Complex Type (cointerface)*             | *Complex Type (cointerface)* |
| Z    | ... *(ellipsis)*                         |                              |

```c++
int *pBased;     // mangled name:  ?pBased@@3PAHA 
int __based(pBased) * pBasedPtr;    // 需要注意Visual C++编译器把这个指针变量的声明解释为：
//         (int __based(pBased) * __based(pBased) pBasedPtr)
//         因此其mangled name: ?pBasedPtr@@3PM2pBased@@HM21@ 
//       其中PM2pBased@@表示这是基于<::pBased>的指针；HM21表示是基于“1”的整型指针，
//       “1”是重复出现的名字的编号简写，这里就是指pBased@ 
//
int __based(void) *pbc; // mangled name: ?pbc@@3PM0HM0 其中的0表示这是__based(void). 
//        编译器把该变量声明解释为(int __based(void) * __based(void) pbc)
```