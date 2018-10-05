#include <stdio.h>
#define n 6  //参加排序的整数个数
//用指针完成冒泡排序，然后逆序排列
void bubble(int *,int *);
void change(int *);

int main() {
    int *ptr,*ptr_old;
    int i,num[n];
    for(i=0;i<=n-1;i++) scanf("%d,",&num[i]);
    ptr_old=num;
    ptr=num;
    bubble(ptr_old,ptr);
    for(i=0;i<=n-1;i++) printf("%d ",*ptr++);
    printf("\n");
    ptr=num;
    change(ptr);
    for(i=0;i<=n-1;i++) printf("%d ",*ptr++);
    printf("\n");
    return 0;
}
//冒泡程序
void bubble(int *ptr_old,int *ptr){
    for(int i=0;i<=n-2;i++){
        ptr=ptr_old;
        int temp;
        for(int k=0;k<=n-2-i;k++){
            if(*ptr>*(ptr+1)){
                temp=*ptr;
                *ptr=*(ptr+1);
                *(ptr+1)=temp;
            }
            ptr++;
        }
    }
    ptr=ptr_old;
}
//交换程序
void change(int *sort){
    int temp;
    for(int i=0;i<=(n-1)/2;i++){
        temp=*(sort+i);
        *(sort+i)=*(sort+n-1-i);
        *(sort+n-1-i)=temp;
    }
}