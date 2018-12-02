#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_INIT_SIZE 1 //初始化链表长度
#define LIST_MAX_SIZE 1000  //没什么用的东西

typedef int Elemtype;

typedef struct LNode  //储存玩具信息
{
	Elemtype ToyId; //质检编号
	char ToyName[20];  //玩具名称
	char ToyProducer[20]; //生产者
	char ToyCompany[20]; //生产部门
	int result;  //质检结果，1为合格，0为不合格 (不能在结构里设默认值！！)
	int error; //质检不合格次数
	char ErrorInfo[100]; //质检不合格时的质量问题
	char Checker[20];  //质检员

	//质检日期
	int year, month, day;
	struct LNode *next;  //指向下一个结构的指针，tail->next 必须为NULL
} Toy, *Link;

typedef struct //用于储存头，尾指针和玩具总数
{
	Link head, tail;  //头，尾指针，头指针不放任何信息，尾指针储存最后一个产品信息
	int len; //玩具总数
} LinkToy;

//可在main里调用的函数
void InitToySet(LinkToy *L);  //初始化质检信息表
void Addto(LinkToy *L); //在下一项添加
void DestroyToySet(LinkToy *L); //销毁链表
void ToyDelete(LinkToy *L);  //在特定点删除元素
void SetElem(LinkToy *L); //改变对应位置的数据
void ShowElem_id(LinkToy *L); //根据产品id显示产品信息
void ShowElem_producer(LinkToy *L); //根据产品生产者显示产品信息

//不可在main里调用的函数
char *s_gets(char *st, int n); //在fgets输入的字符数组后面，把'\n'替换成'\0'
bool ToyNumCheck(LinkToy *L, int get_numer); //检测输入的编号是否早已存在，是则返回true
bool ToyProducerCheck(LinkToy *L, char *get_producer); //检测输入的生产者是否早已存在，是则返回true
Link GetIdPosition(LinkToy *L, int i); //返回相应产品编号所在的节点
Link GetProducerPosition(LinkToy *L, char *producer);  //返回相应产品生产者所在的节点