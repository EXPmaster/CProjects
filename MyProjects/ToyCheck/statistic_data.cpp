//ͳ��ϵͳ
#include "statistic_data.h"

//ͳ�Ƹ�������������ֵĴ���
void StatisticErrorInfo(LinkToy *L)
{
	Link current = L->head->next;
	ErrorInfo problem = {
		0,0,0,0
	};  //��ʼ����������Ϊ0
	while (current)
	{
		if (current->result == 0)  //������������ʱ������switch
		{
			switch (current->ErrorInfo[0])  //��������Ϣ�е���Ԫ��
			{
				case -55: problem.design++;  //��ƣ����衱�ֶ�Ӧ��2��ASCII��ĵ�һ��Ϊ55��
							break;
				case -41: problem.Settings++;	//װ��
							break;
				case -68: problem.Process++; //�ӹ�
							break;
				default: problem.Else++;
							break;
			}
		}
		current = current->next;
	}
	puts("����ͳ�ƣ�");
	printf("���ȱ�����⣺%d ��\n", problem.design);
	printf("װ���������⣺%d ��\n", problem.Settings);
	printf("�ӹ��������⣺%d ��\n", problem.Process);
	//printf("�������⣺%d ��\n", problem.Else);  
}