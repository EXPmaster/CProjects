#pragma once
#include "list.h"

typedef struct ErrorType  //���ڴ������������ֵĴ���
{
	int design;  //�������
	int Settings;  //װ������
	int Process;  //�ӹ�����
	int Else; //��������
} ErrorInfo;

//����main����õĺ���
void StatisticErrorInfo(LinkToy *L);  //ͳ�Ƹ�������������ֵĴ���