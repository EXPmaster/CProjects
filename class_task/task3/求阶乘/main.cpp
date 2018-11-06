#include <stdio.h>
long long jie_cheng(int n); //求阶乘  注意：老版本的编译器可能不支持long long类型！！！

int main()
{
    int n;
    while (!scanf("%d", &n)) //输入判定，scanf的返回值为1时才继续执行,确保正确的输入\
                                    ps. scanf的返回值不是输入值
    {
        fflush(stdin);
        printf("Error data type\n");
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d!\t%lld", i, jie_cheng(i));
        if (i % 3 == 0)
            printf("\n");
        else
            printf("\t");
    }
	return 0;
}

long long jie_cheng(int n)  //阶乘（递归方案）————该算法对内存开销极大，不推荐，但可了解
{
    if (n == 1)
        return 1;
    else
        return n * jie_cheng(n - 1);
}