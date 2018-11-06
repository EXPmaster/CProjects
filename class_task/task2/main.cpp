#include <stdio.h>
//第二次上机任务代码

void F_C();  //华氏度转摄氏度
void change_time();  //时间转换
void yi_huo();  //按位异或

int main()
{
    //测试
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
    char chars[50],number[50];  //这几个50可以换成任意足够大的数字
    int outcome[50];
    printf("Please enter 8 chars\n");
    fgets(chars,8,stdin);  //该函数第一个参数为字符数组的首地址，第二个为最大输入的字符数量
    fflush(stdin);  //清空键盘缓存
    printf("Please enter 8 integers\n");
    fgets(number,8,stdin);
    fflush(stdin);
    for(int i=0;i<8;i++)
        outcome[i]=chars[i]^number[i];
    for(int i=0;i<8;i++)
        printf("%d ",outcome[i]);
}