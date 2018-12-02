
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Initial_Sort();
void reverse_chars(); //字符串反转
void buf8_to_buf10(); //8进制转10进制
void Cgrade(); //C语言考试成绩
char *s_gets(char *ch,int n);
void getLocation();  //返回数组位置
void problem5(); //字符串中字母统计
bool is_questionmark(char *);
void searchName();  //二分查找

typedef struct dataset
{
	char name[100];
	int score;
} Student, Alphabet;

FILE *fp;

int main()
{
    //reverse_chars();
    buf8_to_buf10();
	//Cgrade();
	//getLocation();
	//searchName();
	system("pause");
    return 0; 
}

void Initial_Sort()
{
	char temp[20];
	int i, j;
	bool is_modified = true;
	char cs[5][20] = { "China", "America", "Japan", "India", "England" };
	for (i = 0; i < 4; i++)
	{
		for (j = 4; j > i; j--)
		{
			if (strcmp(cs[j - 1], cs[j]) > 0)
			{
				is_modified = false;
				strcpy(temp, cs[j - 1]);
				strcpy(cs[j - 1], cs[j]);
				strcpy(cs[j], temp);
			}
		}
		if (!is_modified) break;  //第一遍下来后不需要交换
	}
	printf("i=%d\n", i);
	for (i = 0; i < 5; i++)
		puts(cs[i]);
}

void reverse_chars()
{
	char init[30], result[30];
	puts("请输入一个字符串");
	fgets(init, 30, stdin);
	int max = strlen(init) - 1;
	for (int i = 0, j = max - 1; i < max; i++, j--)
	{
		result[j] = init[i];
	}
	result[max] = '\0';
	printf("%s\n", result);
}

void buf8_to_buf10()
{
	puts("请输入一个8进制数");
	int get;
	char string[20];
	int result = 0;
	scanf("%o", &get);
	printf("%d\n", get);
	while (getchar() != '\n');
	puts("请输入相同的8进制数");
	fgets(string, 20, stdin);
	for (int i = 0; string[i] != '\n'; i++)
	{
		result = result * 8 + (string[i] - '0');
	}
	printf("%d\n", result);

}

void Cgrade()
{
	srand((unsigned int)time(0));
	Student data[30];
	if ((fp = fopen("dataset.txt", "r")) == NULL)
	{
		puts("Cannot open file.");
		exit(0);
	}
	for (int i = 0; i < 30; i++)
	{
		s_gets(data[i].name, 20);
		data[i].score = rand() % 100 + 1;
	}

	Student temp;
	for (int i = 0; i < 29; i++)
	{
		int max = i;
		for (int j = i + 1; j < 30; j++)
		{
			if (data[max].score < data[j].score)
				max = j;
		}
		if (max != i)
		{
			temp = data[i];
			data[i] = data[max];
			data[max] = temp;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%2d\t%-10s%10d\n", i + 1, data[i].name, data[i].score);
	}
}


char *s_gets(char *ch, int n)
{
	char *find, *get;
	get = fgets(ch, n, fp);
	if (get)
	{
		find = strchr(ch, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n');
	}
	return get;
}

void getLocation()
{
	srand((unsigned int)time(0));
	int arr[11];
	for (int i = 0; i < 10; arr[i++] = rand() % 50 + 1);
	for (int i = 0; i < 10; printf("%d ", arr[i++]));
	printf("\n");

	for (int i = 0; i < 9; i++) //arrange
	{
		int temp;
		int max = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (arr[i] < arr[j])
				max = j;
		}
		if (max != i)
		{
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp;
		}
	}
	for (int i = 0; i < 10; printf("%d ", arr[i++]));

	int answer[11], know, flag = 0, k = 0;
	puts("Enter the number you want to know the location.");
	scanf_s("%d", &know);

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] == know)
		{
			flag = 1;
			answer[k++] = i;
		}
	}
	if (!flag)
		puts("The number is not in the array.");
	else
	{
		printf("The location is:\n");
		//printf("k=%d",k);
		for (int i = 0; i < k; printf("%d ", answer[i++]));
	}
}

void problem5()
{
	Alphabet result[100];
	char string[100], get[100], statistic[52] = { 0 };
	int k = 0;
	puts("Enter a string");
	fgets(string, 100, stdin);
	while (!is_questionmark(string))
	{
		puts("Cannot find a question mark at the end of the file.");
		puts("Enter again.");
		fgets(string, 100, stdin);
	}
	//printf("%d\n",strlen(string));

	for (int i = 0; i < strlen(string) - 1; i++)
	{
		if (string[i] >= 'A' &&string[i] <= 'Z' || string[i] >= 'a' && string[i] <= 'z')
			get[k++] = string[i];
	}

	//字母排序
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = 0; j < k - 1 - i; j++)
		{
			if (get[j + 1] < get[j])
			{
				char temp = get[j + 1];
				get[j + 1] = get[j];
				get[j] = temp;
			}
		}
	}
	for (int i = 0; i < k; i++)
	{
		if (get[i] >= 'A' && get[i] <= 'Z')
			statistic[get[i] - 'A']++;
		else
			statistic[get[i] - 'a' + ('a' - 'A')]++;
		printf("%c ", get[i]);
	}
	puts("");

	//将信息存入结构
	Alphabet temp;
	int len = 0;
	for (int i = 0; i < 52; i++)
	{
		if (statistic[i])
		{
			if (i < 26) 
				result[len].name[0] = (char)(i + 'A');
			else
				result[len].name[0] = (char)(i-26 + 'a');
			result[len].score = statistic[i];
			len++;
		}
	}
	//排序，按出现次数以及首字母
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (result[j + 1].score > result[j].score)
			{
				temp = result[j + 1];
				result[j + 1] = result[j];
				result[j] = temp;
			}
			else if (result[j + 1].score == result[j].score)
			{
				if (result[j + 1].name[0] < result[j].name[0])
				{
					temp = result[j + 1];
					result[j + 1] = result[j];
					result[j] = temp;
				}
			}
		}
	}


	for (int i = 0; i < len; i++)
		printf("%c\t%d\n", result[i].name[0], result[i].score);

}

bool is_questionmark(char *ch)
{
	int len = strlen(ch) - 1;
	return ch[len - 1] == '?';
}

void searchName()
{
	char name[15][20] = { "Bob", "Alice","Cindy","David","Winko",
		"Leo","Lauran","Hugo","Peter","Ross",
		"Angelina","Bryce","Juliana","Cauchy","Maxwell" };
	char getName[20], temp[20];
	bool flag = false;
	puts("请输入你要查找的名字");
	scanf("%s", getName);
	//printf("%s\n", getName);
	for (int i = 0; i < 14; i++)
	{
		for (int j = 0; j < 14 - i; j++)
		{
			if (strcmp(name[j], name[j+1]) > 0)
			{
				strcpy(temp, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], temp);
			}
		}
	}
	for (int i = 0; i < 15; i++)
		printf("%s ", name[i]);
	printf("\n");

	int middle, left = 0, right = 14;
	while(left <= right)
	{
		middle = (left + right) / 2;
		if (strcmp(getName, name[middle]) > 0) //目标在它之后
			left = middle + 1;
		else if (strcmp(getName, name[middle]) < 0)
			right = middle - 1;
		else if (strcmp(getName, name[middle]) == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
		printf("The location is: %d\n", middle);
	else
		printf("Cannot find it.\n");
}