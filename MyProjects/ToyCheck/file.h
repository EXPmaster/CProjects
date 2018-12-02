#pragma once
#include "list.h"

//可在main里调用的函数
void OpenFile(); //打开指定文件
void GetFile(LinkToy *L);  //获取文件中的数据
void SaveInfo(LinkToy *L); //将数据保存至文件

//不可在main里调用的函数
char *s_fgets(char *st, int n);