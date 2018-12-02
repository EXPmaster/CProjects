//管理系统
#if 0
#include "list.h"
extern FILE *fp; //申明全局文件变量

//初始化链表，头结点不储存信息
void InitToySet(LinkToy *L)
{
	L->head = (Link)malloc(sizeof(Toy));  //给头结点分配空间
	if (!L->head) //空间分配失败
	{
		puts("Initialize failed.");
		exit(0);
	}
	L->tail = L->head;  //尾指针和头指针指向同一位置
	L->head->next = NULL;  //尾指针next指向空
	L->len = LIST_INIT_SIZE-1;  //最初玩具数量为0
}

//添加新的玩具质检信息
void Addto(LinkToy *L)
{
	//新分配空间用于储存信息
	Link p = (Link)malloc(sizeof(Toy));
	L->tail->next = p;
	p->next = NULL;

	//各种输入
	puts("请输入你想添加的产品编号");
	while (!scanf_s("%d", &p->ToyId) || ToyNumCheck(L, p->ToyId))  //输入数据不是整数或与现有的编号重复，则进入循环
	{
		puts("产品编号不合法，请重新输入");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	puts("请输入产品名称");
	s_gets(p->ToyName, 20);

	puts("请输入产品生产者");
	s_gets(p->ToyProducer, 20);

	puts("请输入产品生产部门");
	s_gets(p->ToyCompany, 20);

	puts("产品是否合格（1为合格，0为不合格）");
	while (!scanf_s("%d", &p->result) || p->result != 0 && p->result != 1)
	{
		puts("输入的合格说明不合法");
		puts("产品是否合格（1为合格，0为不合格）");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');

	if (!p->result)   //需要输入质检错误信息
	{
		p->error = 1;  //不合格次数为1
		puts("请输入质检错误信息");
		s_gets(p->ErrorInfo, 100);
	}
	else  //不需要输入质检错误信息
	{
		p->error = 0;
		
	}

	puts("请输入质检员姓名");
	s_gets(p->Checker, 20);

	//日期合法性校验
	/*
	bool error = true;
	while (error)
	{
		//error = false;
		puts("请输入质检日期");
		s_gets(p->CheckTime, 20);
		//int i = 0;

		if (p->CheckTime[0] =='2') //年
		{
			if (p->CheckTime[3] == '.') //月
			{
				if (p->CheckTime[4] == '0' && (p->CheckTime[5] == '1' || p->CheckTime[5] == '3'|| p->CheckTime[5] == '5' ||
					p->CheckTime[5] == '7' || p->CheckTime[5] == '8') ||
					p->CheckTime[4] == '1' && (p->CheckTime[5] =='0' || p->CheckTime[5] == '2')) //有31天的月份
				{
					if (p->CheckTime[6] == '.') //日
					{
						if ((p->CheckTime[7] =='0' && p->CheckTime[8] >'0' && p->CheckTime[8] <='9') || //第一位为0，则第二位可以是1-9
							(p->CheckTime[7] > '0' && p->CheckTime[7] <= '2' && p->CheckTime[8] >='0' && p->CheckTime[8] <= '9')|| //第一位是1或2，则第二位可以是0-9
							(p->CheckTime[7] =='3' && (p->CheckTime[8] == '0' || p->CheckTime[8] == '1')) ) //第一位是3，则第二位可以是0,1
						{
							error = false;
						}

					}
				} //31 days
				else if()//有30天的月份
			}
			error = true;
			puts("日期类型错误");
		}
	}
	*/
	//以上算法放弃

	puts("请输入质检日期:年，月，日（必须为整数，中间用回车隔开）");

	//输入年
	while (!scanf_s("%d", &p->year) || p->year < 2000 || p->year > 3000)
	{
		puts("输入的年份不合法！");
		puts("请重新输入年份");
		while (getchar() != '\n');  //清除缓存
	}
	while (getchar() != '\n'); //清除缓存

	//输入月
	while (!scanf_s("%d", &p->month) || p->month < 1 || p->month > 12)
	{
		puts("输入的月份不合法！");
		puts("请重新输入月份");
		while (getchar() != '\n'); //清除缓存
	}
	while (getchar() != '\n');  //清除缓存

	//输入日
	while (1)
	{
		while (!scanf_s("%d", &p->day))
		{
			puts("输入的日期不合法！");
			puts("请重新输入日期");
			while (getchar() != '\n');  //清除缓存
		}
		//31天的月份
		if (p->month == 1 || p->month == 3 || p->month == 5 ||
			p->month == 7 || p->month == 8 || p->month == 10 || p->month == 12)
		{
			if (p->day >= 1 && p->day <= 31)
				break;
		}
		//30天的月份
		if (p->month == 4 || p->month == 6 || p->month == 9 || p->month == 11)
		{
			if (p->day >= 1 && p->day <= 30)
				break;
		}
		//2月单独判断，闰年或平年
		if (p->month == 2)
		{
			if ((p->year % 4 == 0) && (p->year % 100 != 0) || p->year % 400 == 0) //闰年，有29天
			{
				if (p->day >= 1 && p->day <= 29)
					break;
			}
			else //平年，有28天
			{
				if (p->day >= 1 && p->day <= 28)
					break;
			}
		}
		puts("输入日期不合法！");
		puts("请重新输入日期");
		while (getchar() != '\n');  //清除缓存
	}

	L->tail = p;  //尾指针指向p
	L->len++;  //玩具总数+1
}

//销毁所有信息
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

 //返回相应产品编号所在的节点
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

//返回相应产品生产者所在的节点
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

//删除指定的质检信息
void ToyDelete(LinkToy *L)  //i表示产品编号
{
	int id; //质检信息id
	puts("请输入你想删除的产品编号");
	scanf_s("%d", &id);
	while (getchar() != '\n'); //清除键盘缓存
	while(!ToyNumCheck(L, id))  //找不到质检信息时，提示质检信息不存在
	{
		puts("质检信息不存在");
		puts("请输入你想删除的产品编号");
		scanf_s("%d", &id);
		while (getchar() != '\n');
	}

	Link previous = L->head, current = L->head->next;
	for (; current != GetIdPosition(L, id); previous = current, current = current->next); //找到对应的产品编号位置
	//删除节点信息
	if(current != L->tail) //如果删除项不在队尾
		previous->next = current->next;  
	else //删除项在队尾
	{
		L->tail = previous;
		L->tail->next = NULL;
	}
	puts("删除成功！");

	L->len--;  //总长度-1
	free(current);
}

//改变产品信息
void SetElem(LinkToy *L)
{
	int id; //质检信息id
	puts("请输入你想修改的产品编号");
	scanf_s("%d", &id);
	while (getchar() != '\n'); //清除键盘缓存
	while (!ToyNumCheck(L, id))  //找不到质检信息时，提示质检信息不存在
	{
		puts("质检信息不存在");
		puts("请输入你想修改的产品编号");
		scanf_s("%d", &id);
		while (getchar() != '\n');
	}

	Link previous = L->head, current = L->head->next;
	for (; current != GetIdPosition(L, id); previous = current, current = current->next); //找到对应的产品编号位置

	//输入质检合格信息
	puts("产品是否合格（1为合格，0为不合格）");
	while (!scanf_s("%d", &current->result) || current->result != 0 && current->result != 1)
	{
		puts("输入的合格说明不合法");
		puts("产品是否合格（1为合格，0为不合格）");
		while (getchar() != '\n');
	}
	while (getchar() != '\n');   //清除键盘缓存

	if (!current->result)   //需要输入质检错误信息
	{
		current->error++;  //不合格次数+1
		puts("请输入质检错误信息");
		s_gets(current->ErrorInfo, 100);
	}
	else; //不需要输入质检错误信息
	puts("信息修改成功");
}

//根据产品id显示产品信息（在屏幕上）
void ShowElem_id(LinkToy *L)  //i为产品号
{
	int id; //质检信息id
	puts("请输入你想显示的产品编号");
	scanf_s("%d", &id);
	while (getchar() != '\n'); //清除键盘缓存
	while (!ToyNumCheck(L, id))  //找不到质检信息时，提示质检信息不存在
	{
		puts("质检信息不存在");
		puts("请输入你想显示的产品编号");
		scanf_s("%d", &id);
		while (getchar() != '\n');
	}

	Link previous = L->head, current = L->head->next;
	for (; current != GetIdPosition(L, id); previous = current, current = current->next); //找到对应的产品编号位置
	
	printf("质检编号: %d\n", current->ToyId);
	printf("名称: %s\n", current->ToyName);
	printf("生产者: %s\n", current->ToyProducer);
	printf("生产部门: %s\n", current->ToyCompany);
	current->result ? printf("质检结果： 合格\n") : printf("质检结果： 不合格\n不合格次数：%d\n质量问题： %s\n", current->error, current->ErrorInfo);
	printf("质检员: %s\n", current->Checker);
	printf("质检日期: %d.%d.%d\n", current->year, current->month, current->day);
}

//根据产品生产者显示产品信息
void ShowElem_producer(LinkToy *L)
{
	char producer[20]; //生产者
	puts("请输入你想显示的产品生产者");
	s_gets(producer, 20);
	while (!ToyProducerCheck(L, producer))  //找不到质检信息时，提示质检信息不存在
	{
		puts("生产者不存在");
		puts("请输入你想显示的产品生产者");
		s_gets(producer, 20);
	}

	Link previous = L->head, current = L->head->next;
	for (; current != GetProducerPosition(L, producer); previous = current, current = current->next); //找到对应的产品编号位置

	printf("质检编号: %d\n", current->ToyId);
	printf("名称: %s\n", current->ToyName);
	printf("生产者: %s\n", current->ToyProducer);
	printf("生产部门: %s\n", current->ToyCompany);
	current->result ? printf("质检结果： 合格\n") : printf("质检结果： 不合格\n不合格次数：%d\n质量问题： %s\n", current->error, current->ErrorInfo);
	printf("质检员: %s\n", current->Checker);
	printf("质检日期: %d.%d.%d\n", current->year, current->month, current->day);
}


//在fgets输入的字符数组后面，把'\n'替换成'\0'
char *s_gets(char *st, int n)
{
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); //找到输入的回车符，并把它替换成'\0'，便于printf("%s",...);
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n'); //清除键盘缓存
	}
	return ret_val;
}

//检测输入的产品编号是否早已存在，是则返回true
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

//检测输入的产品生产者是否早已存在，是则返回true （可考虑改用strcmp函数）
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