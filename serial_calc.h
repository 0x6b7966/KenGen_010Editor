#pragma once
#include <Windows.h>

// 获取人数
DWORD GetRandNum();

// 获取字符串加密后的数据
void GetEncryStr( const char *szName, DWORD regmen, DWORD day );

// 序列号计算
void CalcReg( const char *szName, DWORD day, bool flag, char serial[ 50 ] );
