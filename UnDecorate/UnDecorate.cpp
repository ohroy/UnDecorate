// UnDecorate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h> //如果不包含此头文件，编译DbgHelp.h时会产生大量语法错误
#include <DbgHelp.h>
#include <tchar.h>
#include <iostream>
#pragma comment(lib,"dbghelp.lib") //告诉链接器使用这个输入库

int _tmain(int argc, _TCHAR* argv[])
{
	WCHAR szUndecorateName[256];
	memset(szUndecorateName, 0, 256);
	if (2 == argc)
	{
		::UnDecorateSymbolNameW(argv[1], szUndecorateName, 256, 0);
		std::wcout << szUndecorateName << std::endl;
	}
    return 0;
}

