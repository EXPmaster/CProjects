#pragma once
#include "list.h"

typedef struct ErrorType  //用于储存各种问题出现的次数
{
	int design;  //设计问题
	int Settings;  //装配质量
	int Process;  //加工质量
	int Else; //其他问题
} ErrorInfo;

//可在main里调用的函数
void StatisticErrorInfo(LinkToy *L);  //统计各种质量问题出现的次数