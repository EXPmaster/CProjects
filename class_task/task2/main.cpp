#include <stdio.h>
//�ڶ����ϻ��������

void F_C();  //���϶�ת���϶�
void change_time();  //ʱ��ת��
void yi_huo();  //��λ���

int main()
{
    //����
    //F_C();
    //change_time();
    //yi_huo();
    return 0;
}

void F_C()
{
    double F, C;
    printf("Please enter F degree:\n");
    scanf("%lf", &F);
    C = (double) 5 / 9 * (F - 32);
    printf("The C degree is %.2lf\n", C);
}

void change_time()
{
    double year, second;
    int day, hour, minute;
    year = 365.2422;
    day = year;
    hour = (year - day) * 24;
    minute = (year - day) * 24 * 60 - hour * 60;
    second = (year - day) * 24 * 3600 - hour * 3600 - minute * 60;
    printf("day:%d\nhour:%d\nminute:%d\nsecond:%lf\n", day, hour, minute, second);
}

void yi_huo()
{
    char chars[50],number[50];  //�⼸��50���Ի��������㹻�������
    int outcome[50];
    printf("Please enter 8 chars\n");
    fgets(chars,8,stdin);  //�ú�����һ������Ϊ�ַ�������׵�ַ���ڶ���Ϊ���������ַ�����
    fflush(stdin);  //��ռ��̻���
    printf("Please enter 8 integers\n");
    fgets(number,8,stdin);
    fflush(stdin);
    for(int i=0;i<8;i++)
        outcome[i]=chars[i]^number[i];
    for(int i=0;i<8;i++)
        printf("%d ",outcome[i]);
}