#pragma once
#include "list.h"

//����main����õĺ���
void OpenFile(); //��ָ���ļ�
void GetFile(LinkToy *L);  //��ȡ�ļ��е�����
void SaveInfo(LinkToy *L); //�����ݱ������ļ�

//������main����õĺ���
char *s_fgets(char *st, int n);