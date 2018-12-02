//统计系统
#include "statistic_data.h"

//统计各种质量问题出现的次数
void StatisticErrorInfo(LinkToy *L)
{
	Link current = L->head->next;
	ErrorInfo problem = {
		0,0,0,0
	};  //初始化各种问题为0
	while (current)
	{
		if (current->result == 0)  //存在质量问题时，进入switch
		{
			switch (current->ErrorInfo[0])  //检查错误信息中的首元素
			{
				case -55: problem.design++;  //设计（“设”字对应的2个ASCII码的第一个为55）
							break;
				case -41: problem.Settings++;	//装配
							break;
				case -68: problem.Process++; //加工
							break;
				default: problem.Else++;
							break;
			}
		}
		current = current->next;
	}
	puts("问题统计：");
	printf("设计缺陷问题：%d 次\n", problem.design);
	printf("装配质量问题：%d 次\n", problem.Settings);
	printf("加工质量问题：%d 次\n", problem.Process);
	//printf("其他问题：%d 次\n", problem.Else);  
}