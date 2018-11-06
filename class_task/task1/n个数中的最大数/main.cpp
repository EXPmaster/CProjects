#include <stdio.h>
#define N 5  //取N个数中的最大数
void max(int *);
int main()
{
    int data[N],*number;
    for(int i=0;i<N;i++) scanf("%d",&data[i]);
    number=data;
    max(number);
    number=&data[N-1];
    printf("%d",*number);
    return 0;
}

void max(int *max)
{
    int k,temp;
    for(k=0;k<N-1;k++)
    {
        if(*max>*(max+1))
        {
            temp=*max;
            *max=*(max+1);
            *(max+1)=temp;
        }
        max++;
    }
}