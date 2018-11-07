#include <stdio.h>
void start(char array[][3]);
void formu(char array[][3]);
void print(char array[][3]);
int main() {
    char array[3][3];
    int game=0;
    start(array);
    printf("Initialize successfully!\n");
    print(array);
    for(;game<9;game++){
        printf("\n\n\n\n\n\n\n\n\n\n");
        printf("The %dth round\nThis is the current circumstance:\n",game+1);
        print(array);
        printf("Please enter your number:\n");
        formu(array);
    }
    printf("\n\n\n\n\n\n\n\n\n\n");
    print(array);
    printf("Game Over.\n");
    return 0;
}

void start(char array[][3]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            array[i][j]='.';
        }
    }
}

void print(char array[][3]) {
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
           printf("%c",array[i][j]);
        }
        printf("\n");
    }
}

void formu(char array[][3]) {
    int get,i,j;
    bool flag=false;
    while(!flag){
        scanf("%d",&get);
        i=(9-get)/3;
        j=2-(9-get)%3;
        if(array[i][j]=='.') {
            array[i][j]='X';
            flag=true;
        }
        else
            printf("The square is occupied. Please try another one.\n");
    }

}