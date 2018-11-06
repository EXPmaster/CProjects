#include <stdio.h>
#include <math.h>

void array_sum();  //数列求和
void array_sum_precision(); //判断精度的数列求和
void sum(); //分段函数求和
void sqr(); //迭代法求平方根

int main()
{
	//sum();
    //array_sum_precision();
	//array_sum();
	return 0;
}

void array_sum() //数列求和（这里只提供从左到右各项相加的思路）
{
    double sum = 0;
    int n;
    printf("n=");
    while (scanf("%d", &n) != 1)  //输入判定，scanf的返回值为1时才继续执行,确保正确的输入\
                                    ps. scanf的返回值不是输入值
    {
        fflush(stdin);
        printf("error number type\n");
        printf("n=");
    }
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)   //奇数项为正，偶数项为负
            sum -= (double) 1 / i;
        else
            sum += (double) 1 / i;
    }
    printf("The sum of the array is %g", sum);
}


void array_sum_precision()  //判断精度的数列求和
{
    double sum, sum0;
    sum = 0;
    sum0 = 10000;
    long long i = 1;
    while (fabs(sum - sum0) >= 1e-6)   //精度太高了会导致很长时间运行不完
    {
        sum0 = sum;
        if (i % 2 == 0)
            sum -= (double) 1 / i;
        else
            sum += (double) 1 / i;
        i++;
        printf("sum-sim0 is %lf\n", fabs(sum - sum0));
    }
    printf("The sum of the array is %lf\n", sum);
    printf("n is %lld", i);
}


void sum()  //分段函数求和
{
    double x, y, z, s;
    printf("x=");
    while (scanf("%lf", &x) != 1)  //输入判定，scanf的返回值为1时才继续执行,确保正确的输入
    {
        fflush(stdin);
        printf("error number type\n");
        printf("x=");
    }
    printf("y=");
    while (scanf("%lf", &y) != 1)
    {
        fflush(stdin);
        printf("error number type\n");
        printf("y=");
    }

    if (x < 0 && y < 0)
        z = exp(x + y);
    else if (x >= 0 && x < 1 && y >= 0)
        z = exp(2 * x - y);
    else if (x >= 1)
        z = log(x);
    s = z + x + y;
    printf("%lf\n", s);
}

void sqr()
{
    double a,s,s_old;
    s=1;
    s_old=10000;
    printf("Enter the number you want to divide\n");
    while (!scanf("%lf", &a))
    {
        fflush(stdin);
        printf("Error data type\n");
        printf("Enter the number you want to divide\n");
    }
    while (fabs(s-s_old) >= 1e-5) 
    {
        s_old = s;
        s=0.5*(s_old+a/s_old);
    }
    printf("The sqr of %g is %g\n",a,s);
}