//����ϵͳ
#if 0
#include "list.h"
extern FILE *fp; //����ȫ���ļ�����

//��ʼ������ͷ��㲻������Ϣ
void InitToySet(LinkToy *L)
{
	L->head = (Link)malloc(sizeof(Toy));  //��ͷ������ռ�
	if (!L->head) //�ռ����ʧ��
	{
		puts("Initialize failed.");
		exit(0);
	}
	L->tail = L->head;  //βָ���ͷָ��ָ��ͬһλ��
	L->head->next = NULL;  //βָ��nextָ���
	L->len = LIST_INIT_SIZE-1;  //����������Ϊ0
}

//����µ�����ʼ���Ϣ
void Addto(LinkToy *L)
{
	//�·���ռ����ڴ�����Ϣ
	Link p = (Link)malloc(sizeof(Toy));
	L->tail->next = p;
	p->next = NULL;

	//��������
	puts("������������ӵĲ�Ʒ���");
	while (!scanf_s("%d", &p->ToyId) || ToyNumCheck(L, p->ToyId))  //�������ݲ��������������еı���ظ��������ѭ��
	{
		puts("��Ʒ��Ų��Ϸ�������������");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	puts("�������Ʒ����");
	s_gets(p->ToyName, 20);

	puts("�������Ʒ������");
	s_gets(p->ToyProducer, 20);

	puts("�������Ʒ��������");
	s_gets(p->ToyCompany, 20);

	puts("��Ʒ�Ƿ�ϸ�1Ϊ�ϸ�0Ϊ���ϸ�");
	while (!scanf_s("%d", &p->result) || p->result != 0 && p->result != 1)
	{
		puts("����ĺϸ�˵�����Ϸ�");
		puts("��Ʒ�Ƿ�ϸ�1Ϊ�ϸ�0Ϊ���ϸ�");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	if (!p->result)   //��Ҫ�����ʼ������Ϣ
	{
		p->error = 1;  //���ϸ����Ϊ1
		puts("�������ʼ������Ϣ");
		s_gets(p->ErrorInfo, 100);
	}
	else  //����Ҫ�����ʼ������Ϣ
	{
		p->error = 0;
		
	}

	puts("�������ʼ�Ա����");
	s_gets(p->Checker, 20);

	//���ںϷ���У��
	/*
	bool error = true;
	while (error)
	{
		//error = false;
		puts("�������ʼ�����");
		s_gets(p->CheckTime, 20);
		//int i = 0;

		if (p->CheckTime[0] =='2') //��
		{
			if (p->CheckTime[3] == '.') //��
			{
				if (p->CheckTime[4] == '0' && (p->CheckTime[5] == '1' || p->CheckTime[5] == '3'|| p->CheckTime[5] == '5' ||
					p->CheckTime[5] == '7' || p->CheckTime[5] == '8') ||
					p->CheckTime[4] == '1' && (p->CheckTime[5] =='0' || p->CheckTime[5] == '2')) //��31����·�
				{
					if (p->CheckTime[6] == '.') //��
					{
						if ((p->CheckTime[7] =='0' && p->CheckTime[8] >'0' && p->CheckTime[8] <='9') || //��һλΪ0����ڶ�λ������1-9
							(p->CheckTime[7] > '0' && p->CheckTime[7] <= '2' && p->CheckTime[8] >='0' && p->CheckTime[8] <= '9')|| //��һλ��1��2����ڶ�λ������0-9
							(p->CheckTime[7] =='3' && (p->CheckTime[8] == '0' || p->CheckTime[8] == '1')) ) //��һλ��3����ڶ�λ������0,1
						{
							error = false;
						}

					}
				} //31 days
				else if()//��30����·�
			}
			error = true;
			puts("�������ʹ���");
		}
	}
	*/
	//�����㷨����

	puts("�������ʼ�����:�꣬�£��գ�����Ϊ�������м��ûس�������");

	//������
	while (!scanf_s("%d", &p->year) || p->year < 2000 || p->year > 3000)
	{
		puts("�������ݲ��Ϸ���");
		puts("�������������");
		while (getchar() != '\n');  //�������
	}
	while (getchar() != '\n'); //�������

	//������
	while (!scanf_s("%d", &p->month) || p->month < 1 || p->month > 12)
	{
		puts("������·ݲ��Ϸ���");
		puts("�����������·�");
		while (getchar() != '\n'); //�������
	}
	while (getchar() != '\n');  //�������

	//������
	while (1)
	{
		while (!scanf_s("%d", &p->day))
		{
			puts("��������ڲ��Ϸ���");
			puts("��������������");
			while (getchar() != '\n');  //�������
		}
		//31����·�
		if (p->month == 1 || p->month == 3 || p->month == 5 ||
			p->month == 7 || p->month == 8 || p->month == 10 || p->month == 12)
		{
			if (p->day >= 1 && p->day <= 31)
				break;
		}
		//30����·�
		if (p->month == 4 || p->month == 6 || p->month == 9 || p->month == 11)
		{
			if (p->day >= 1 && p->day <= 30)
				break;
		}
		//2�µ����жϣ������ƽ��
		if (p->month == 2)
		{
			if ((p->year % 4 == 0) && (p->year % 100 != 0) || p->year % 400 == 0) //���꣬��29��
			{
				if (p->day >= 1 && p->day <= 29)
					break;
			}
			else //ƽ�꣬��28��
			{
				if (p->day >= 1 && p->day <= 28)
					break;
			}
		}
		puts("�������ڲ��Ϸ���");
		puts("��������������");
		while (getchar() != '\n');  //�������
	}

	L->tail = p;  //βָ��ָ��p
	L->len++;  //�������+1
}

//����������Ϣ
void DestroyToySet(LinkToy *L)
{
	Link current, previous;
	current = previous = L->head;
	L->len = 0;
	while (current)
	{
		previous = current;
		current = current->next;
		free(previous);
	}
	puts("Destroy finished.");
}

 //������Ӧ��Ʒ������ڵĽڵ�
Link GetIdPosition(LinkToy *L, int i)
{
	Link current = L->head->next;
	while (current->ToyId != i && current != NULL)
	{
		current = current->next;
	}
	if (!current)
		exit(0);
	return current;
}

//������Ӧ��Ʒ���������ڵĽڵ�
Link GetProducerPosition(LinkToy *L, char *producer)
{
	Link current = L->head->next;
	while (current)
	{
		int count = 0;
		for (int i = 0; producer[i] != '\0'; i++)
		{
			if (current->ToyProducer[i] == producer[i])
				count++;
		}

		if (count == strlen(producer))
			return current;
		current = current->next;
	}
	exit(0);
}

//ɾ��ָ�����ʼ���Ϣ
void ToyDelete(LinkToy *L)  //i��ʾ��Ʒ���
{
	int id; //�ʼ���Ϣid
	puts("����������ɾ���Ĳ�Ʒ���");
	scanf_s("%d", &id);
	while (getchar() != '\n'); //������̻���
	while(!ToyNumCheck(L, id))  //�Ҳ����ʼ���Ϣʱ����ʾ�ʼ���Ϣ������
	{
		puts("�ʼ���Ϣ������");
		puts("����������ɾ���Ĳ�Ʒ���");
		scanf_s("%d", &id);
		while (getchar() != '\n');
	}

	Link previous = L->head, current = L->head->next;
	for (; current != GetIdPosition(L, id); previous = current, current = current->next); //�ҵ���Ӧ�Ĳ�Ʒ���λ��
	//ɾ���ڵ���Ϣ
	if(current != L->tail) //���ɾ����ڶ�β
		previous->next = current->next;  
	else //ɾ�����ڶ�β
	{
		L->tail = previous;
		L->tail->next = NULL;
	}
	puts("ɾ���ɹ���");

	L->len--;  //�ܳ���-1
	free(current);
}

//�ı��Ʒ��Ϣ
void SetElem(LinkToy *L)
{
	int id; //�ʼ���Ϣid
	puts("�����������޸ĵĲ�Ʒ���");
	scanf_s("%d", &id);
	while (getchar() != '\n'); //������̻���
	while (!ToyNumCheck(L, id))  //�Ҳ����ʼ���Ϣʱ����ʾ�ʼ���Ϣ������
	{
		puts("�ʼ���Ϣ������");
		puts("�����������޸ĵĲ�Ʒ���");
		scanf_s("%d", &id);
		while (getchar() != '\n');
	}

	Link previous = L->head, current = L->head->next;
	for (; current != GetIdPosition(L, id); previous = current, current = current->next); //�ҵ���Ӧ�Ĳ�Ʒ���λ��

	//�����ʼ�ϸ���Ϣ
	puts("��Ʒ�Ƿ�ϸ�1Ϊ�ϸ�0Ϊ���ϸ�");
	while (!scanf_s("%d", &current->result) || current->result != 0 && current->result != 1)
	{
		puts("����ĺϸ�˵�����Ϸ�");
		puts("��Ʒ�Ƿ�ϸ�1Ϊ�ϸ�0Ϊ���ϸ�");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');   //������̻���

	if (!current->result)   //��Ҫ�����ʼ������Ϣ
	{
		current->error++;  //���ϸ����+1
		puts("�������ʼ������Ϣ");
		s_gets(current->ErrorInfo, 100);
	}
	else; //����Ҫ�����ʼ������Ϣ
	puts("��Ϣ�޸ĳɹ�");
}

//���ݲ�Ʒid��ʾ��Ʒ��Ϣ������Ļ�ϣ�
void ShowElem_id(LinkToy *L)  //iΪ��Ʒ��
{
	int id; //�ʼ���Ϣid
	puts("������������ʾ�Ĳ�Ʒ���");
	scanf_s("%d", &id);
	while (getchar() != '\n'); //������̻���
	while (!ToyNumCheck(L, id))  //�Ҳ����ʼ���Ϣʱ����ʾ�ʼ���Ϣ������
	{
		puts("�ʼ���Ϣ������");
		puts("������������ʾ�Ĳ�Ʒ���");
		scanf_s("%d", &id);
		while (getchar() != '\n');
	}

	Link previous = L->head, current = L->head->next;
	for (; current != GetIdPosition(L, id); previous = current, current = current->next); //�ҵ���Ӧ�Ĳ�Ʒ���λ��
	
	printf("�ʼ���: %d\n", current->ToyId);
	printf("����: %s\n", current->ToyName);
	printf("������: %s\n", current->ToyProducer);
	printf("��������: %s\n", current->ToyCompany);
	current->result ? printf("�ʼ����� �ϸ�\n") : printf("�ʼ����� ���ϸ�\n���ϸ������%d\n�������⣺ %s\n", current->error, current->ErrorInfo);
	printf("�ʼ�Ա: %s\n", current->Checker);
	printf("�ʼ�����: %d.%d.%d\n", current->year, current->month, current->day);
}

//���ݲ�Ʒ��������ʾ��Ʒ��Ϣ
void ShowElem_producer(LinkToy *L)
{
	char producer[20]; //������
	puts("������������ʾ�Ĳ�Ʒ������");
	s_gets(producer, 20);
	while (!ToyProducerCheck(L, producer))  //�Ҳ����ʼ���Ϣʱ����ʾ�ʼ���Ϣ������
	{
		puts("�����߲�����");
		puts("������������ʾ�Ĳ�Ʒ������");
		s_gets(producer, 20);
	}

	Link previous = L->head, current = L->head->next;
	for (; current != GetProducerPosition(L, producer); previous = current, current = current->next); //�ҵ���Ӧ�Ĳ�Ʒ���λ��

	printf("�ʼ���: %d\n", current->ToyId);
	printf("����: %s\n", current->ToyName);
	printf("������: %s\n", current->ToyProducer);
	printf("��������: %s\n", current->ToyCompany);
	current->result ? printf("�ʼ����� �ϸ�\n") : printf("�ʼ����� ���ϸ�\n���ϸ������%d\n�������⣺ %s\n", current->error, current->ErrorInfo);
	printf("�ʼ�Ա: %s\n", current->Checker);
	printf("�ʼ�����: %d.%d.%d\n", current->year, current->month, current->day);
}


//��fgets������ַ�������棬��'\n'�滻��'\0'
char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); //�ҵ�����Ļس������������滻��'\0'������printf("%s",...);
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n'); //������̻���
	}
	return ret_val;
}

//�������Ĳ�Ʒ����Ƿ����Ѵ��ڣ����򷵻�true
bool ToyNumCheck(LinkToy *L, int get_number)
{
	Link current = L->head->next;
	while (current != L->tail->next)
	{
		if (current->ToyId == get_number)
			return true;
		current = current->next;
	}
	return false;
}

//�������Ĳ�Ʒ�������Ƿ����Ѵ��ڣ����򷵻�true ���ɿ��Ǹ���strcmp������
bool ToyProducerCheck(LinkToy *L, char *get_producer)
{
	Link current = L->head->next;
	while (current != L->tail->next)
	{
		int count = 0;
		for (int i = 0; get_producer[i] != '\0'; i++)
		{
			if (current->ToyProducer[i] == get_producer[i])
				count++;
		}

		if (count == strlen(get_producer))
			return true;
		
		current = current->next;
	}
	return false;
}

#endif