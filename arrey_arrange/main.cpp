#include <stdio.h>
#define SIZE 4
//对n x n数组进行冒泡排序,从小到大
void input(int array[SIZE][SIZE]);
void print(int array[SIZE][SIZE]);
void up_demension(int array[SIZE][SIZE],int d_array[]);
void down_demension(int array[SIZE][SIZE],int d_array[]);
void bubble(int *,int *);
int main() {
    int array[SIZE][SIZE];
    int d_array[SIZE*SIZE];
    int *ptr,*ptr_old;
    input(array);
    print(array);
    down_demension(array,d_array);
    ptr=d_array;
    ptr_old=d_array;
    bubble(ptr_old,ptr);
    up_demension(array,d_array);
    print(array);
    return 0;
}

void input(int array[SIZE][SIZE]){
    int i,k;
    for(i=0;i<SIZE;i++){
        for(k=0;k<SIZE;k++){
            scanf("%d",&array[i][k]);
        }
    }
}

void print(int array[SIZE][SIZE]){
    int i,k;
    for(i=0;i<SIZE;i++){
        for(k=0;k<SIZE;k++){
            printf("%d ",array[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}

void bubble(int *ptr_old,int *ptr){
    for(int i=0;i<SIZE*SIZE-1;i++){
        ptr=ptr_old;
        int temp;
        for(int k=0;k<SIZE*SIZE-1-i;k++){
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

void down_demension(int array[SIZE][SIZE],int d_array[SIZE*SIZE]){
    int i,j;
    int k=0;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            d_array[k]=array[i][j];
            k++;
        }
    }
}

void up_demension(int array[SIZE][SIZE],int d_array[SIZE*SIZE]){
    int i,j;
    int k=0;
    for(i=0;i<SIZE;i++){
        for(j=0;j<SIZE;j++){
            array[i][j]=d_array[k];
            k++;
        }
    }
}