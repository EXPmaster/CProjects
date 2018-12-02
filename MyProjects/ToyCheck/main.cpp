//主文件，用于各种操作

#include"list.h"
#include "file.h"
#include "statistic_data.h"

int main()
{
	//准备工作（使用前记得自己在目录中建一个database.txt，不然会提示无法打开文件）
	LinkToy T;
	InitToySet(&T);
	OpenFile();
	GetFile(&T);
	printf("现有产品数：%d\n", T.len);

	//以下是要执行的操作，自己添加，用于测试（参考 list.h, file.h, statistic_data 里的函数）

	

	DestroyToySet(&T); //main结束前必加，用于free
	return 0;
}