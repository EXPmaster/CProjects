//文件操作

#define _CRT_SECURE_NO_DEPRECATE //防止scanf等报错
#include "file.h"

FILE *fp; //文件指针

//打开指定文件
void OpenFile()
{
	if ((fp = fopen("database.txt", "r")) == NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
}

//从文件中读取数据
void GetFile(LinkToy *L)
{
	while (1) //判断文件是否结束
	{
		//新分配空间用于储存信息
		Link p = (Link)malloc(sizeof(Toy));
		L->tail->next = p;
		p->next = NULL;

		//各种读取
		if (fscanf(fp, "%d\n", &p->ToyId) == EOF) //读到文件末尾则销毁该节点
		{
			free(p);
			L->tail->next = NULL;  //这句很重要！！！（调试了一个小时才发现的安全隐患......）
			return;
		}
		s_fgets(p->ToyName, 20);
		s_fgets(p->ToyProducer, 20);
		s_fgets(p->ToyCompany, 20);
		fscanf(fp, "%d\n", &p->result);
		fscanf(fp, "%d\n", &p->error);

		if (!p->result)   //判断是否需要读入质检错误信息
		{
			s_fgets(p->ErrorInfo, 100);
		}

		s_fgets(p->Checker, 20);
		fscanf(fp, "%d.", &p->year);
		fscanf(fp, "%d.", &p->month);
		fscanf(fp, "%d\n", &p->day);
		
		L->tail = p;
		L->len++;
	}
	fclose(fp);
}

//将数据保存进文件
void SaveInfo(LinkToy *L)
{
	fp = fopen("database.txt", "w");
	Link current = L->head->next;
	while (current)  //各种输出
	{
		fprintf(fp, "%d\n", current->ToyId);
		fprintf(fp, "%s\n", current->ToyName);
		fprintf(fp, "%s\n", current->ToyProducer);
		fprintf(fp, "%s\n", current->ToyCompany);
		current->result ? fprintf(fp, "%d\n%d\n", 1, current->error) : fprintf(fp, "%d\n%d\n%s\n", 0, current->error, current->ErrorInfo);
		fprintf(fp, "%s\n", current->Checker);
		fprintf(fp, "%d.%d.%d\n", current->year, current->month, current->day);
		current = current->next;
	}
	fclose(fp);
}

//原理同s_gets()
char *s_fgets(char *st, int n)
{
	{
		char *ret_val;
		char *find;
		ret_val = fgets(st, n, fp);
		if (ret_val)
		{
			find = strchr(st, '\n');
			if (find)
				*find = '\0';
			else
				while (getchar() != '\n');
		}
		return ret_val;
	}
}