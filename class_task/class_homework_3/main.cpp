#include <stdio.h>

int sum(int a, int b, int n);  //an前n项和

void yinzi(); //2的因子个数

int total = 0;

int main()
{
    /*
    int a = 8, b = 1, n = 3;
    int total;
    total = sum(a, b + 3, n);
    printf("%d\n", total);
     */
    yinzi();
    return 0;
}

int sum(int a, int b, int n)
{
    if (n == 1)
        return a;
    else
        return a + sum(a + b, b + 3, n - 1);
}

void yinzi()
{
    int input, n = 0;
    puts("please enter an integer:");
    scanf("%d", &input);
    for (; input % 2 == 0; input /= 2, n++);
    printf("%d\n", n);
}

