#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 50  //产生1-NUM的随机数

void guessing_game(int *, int *);  //猜数字游戏

int getrand();  //获取随机数

int main()
{
    int win = 0;
    int guess = 0;
    guessing_game(&win, &guess);
    if (win)
        printf("Good luck!\n");
    else
        printf("Bad luck! You didn't get the answer.\n");
    printf("you've guessed %d times!\n", guess);
    printf("that's the end.Thank you!\n");
    return 0;
}

void guessing_game(int *win, int *guess)
{
    int b = getrand();
    int v;
    while (*guess < 20)
    {
        printf("the number is:\n");
        scanf("%d", &v);
        if (v < b)
            printf("too small\n\n");
        else if (v > b)
            printf("too big\n\n");
        else
        {
            printf("right\n\n");
            ++*guess;
            ++*win;
            break;
        }
        ++*guess;
    }
}

int getrand()
{
    srand((unsigned int) time(0));
    return rand() % NUM + 1;  
}