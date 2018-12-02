//�ļ�����

#define _CRT_SECURE_NO_DEPRECATE //��ֹscanf�ȱ���
#include "file.h"

FILE *fp; //�ļ�ָ��

//��ָ���ļ�
void OpenFile()
{
	if ((fp = fopen("database.txt", "r")) == NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
}

//���ļ��ж�ȡ����
void GetFile(LinkToy *L)
{
	while (1) //�ж��ļ��Ƿ����
	{
		//�·���ռ����ڴ�����Ϣ
		Link p = (Link)malloc(sizeof(Toy));
		L->tail->next = p;
		p->next = NULL;

		//���ֶ�ȡ
		if (fscanf(fp, "%d\n", &p->ToyId) == EOF) //�����ļ�ĩβ�����ٸýڵ�
		{
			free(p);
			L->tail->next = NULL;  //������Ҫ��������������һ��Сʱ�ŷ��ֵİ�ȫ����......��
			return;
		}
		s_fgets(p->ToyName, 20);
		s_fgets(p->ToyProducer, 20);
		s_fgets(p->ToyCompany, 20);
		fscanf(fp, "%d\n", &p->result);
		fscanf(fp, "%d\n", &p->error);

		if (!p->result)   //�ж��Ƿ���Ҫ�����ʼ������Ϣ
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

//�����ݱ�����ļ�
void SaveInfo(LinkToy *L)
{
	fp = fopen("database.txt", "w");
	Link current = L->head->next;
	while (current)  //�������
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

//ԭ��ͬs_gets()
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