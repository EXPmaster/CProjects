//���ļ������ڸ��ֲ���

#include"list.h"
#include "file.h"
#include "statistic_data.h"

int main()
{
	//׼��������ʹ��ǰ�ǵ��Լ���Ŀ¼�н�һ��database.txt����Ȼ����ʾ�޷����ļ���
	LinkToy T;
	InitToySet(&T);
	OpenFile();
	GetFile(&T);
	printf("���в�Ʒ����%d\n", T.len);

	//������Ҫִ�еĲ������Լ���ӣ����ڲ��ԣ��ο� list.h, file.h, statistic_data ��ĺ�����

	

	DestroyToySet(&T); //main����ǰ�ؼӣ�����free
	return 0;
}