#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_INIT_SIZE 1 //��ʼ��������
#define LIST_MAX_SIZE 1000  //ûʲô�õĶ���

typedef int Elemtype;

typedef struct LNode  //���������Ϣ
{
	Elemtype ToyId; //�ʼ���
	char ToyName[20];  //�������
	char ToyProducer[20]; //������
	char ToyCompany[20]; //��������
	int result;  //�ʼ�����1Ϊ�ϸ�0Ϊ���ϸ� (�����ڽṹ����Ĭ��ֵ����)
	int error; //�ʼ첻�ϸ����
	char ErrorInfo[100]; //�ʼ첻�ϸ�ʱ����������
	char Checker[20];  //�ʼ�Ա

	//�ʼ�����
	int year, month, day;
	struct LNode *next;  //ָ����һ���ṹ��ָ�룬tail->next ����ΪNULL
} Toy, *Link;

typedef struct //���ڴ���ͷ��βָ����������
{
	Link head, tail;  //ͷ��βָ�룬ͷָ�벻���κ���Ϣ��βָ�봢�����һ����Ʒ��Ϣ
	int len; //�������
} LinkToy;

//����main����õĺ���
void InitToySet(LinkToy *L);  //��ʼ���ʼ���Ϣ��
void Addto(LinkToy *L); //����һ�����
void DestroyToySet(LinkToy *L); //��������
void ToyDelete(LinkToy *L);  //���ض���ɾ��Ԫ��
void SetElem(LinkToy *L); //�ı��Ӧλ�õ�����
void ShowElem_id(LinkToy *L); //���ݲ�Ʒid��ʾ��Ʒ��Ϣ
void ShowElem_producer(LinkToy *L); //���ݲ�Ʒ��������ʾ��Ʒ��Ϣ

//������main����õĺ���
char *s_gets(char *st, int n); //��fgets������ַ�������棬��'\n'�滻��'\0'
bool ToyNumCheck(LinkToy *L, int get_numer); //�������ı���Ƿ����Ѵ��ڣ����򷵻�true
bool ToyProducerCheck(LinkToy *L, char *get_producer); //���������������Ƿ����Ѵ��ڣ����򷵻�true
Link GetIdPosition(LinkToy *L, int i); //������Ӧ��Ʒ������ڵĽڵ�
Link GetProducerPosition(LinkToy *L, char *producer);  //������Ӧ��Ʒ���������ڵĽڵ�