#include <stdio.h>

#define min(a, b) ((a<b)?a:b)

int zhanzhuan(int,int);
int main()
{
    int a, b, i;
    int temp = 0;
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);

    /*1.ö�ٷ�
    for(i=1;i<=min(a,b);i++)
    {
        if((double)a/i==a/i && (double)b/i==b/i)
        {
            temp=i;
        }
    }
     ------------------------------------------
    */

    /*2.շת�����
    while (a % b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    printf("%d\n", b);
     -----------------------------------------
     */
    //3.շת����ĵݹ��ʾ
    printf("%d\n", zhanzhuan(a,b));
    return 0;
}

int zhanzhuan(int a, int b) //�ݹ�
{
    if(b==0)
        return a;
    else
        return zhanzhuan(b,a%b);
}