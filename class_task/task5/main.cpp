#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void max_of_array();

void back_text();

void find_item();

int main()
{
    //max_of_array();
    //back_text();
    find_item();
    return 0;
}

void max_of_array()
{
    srand((unsigned int) time(0));
    int array[10];
    int temp = 0, mark[20] = {100};
    int k = 0;

    for (int i = 0; i < 10; i++)
    {
        //array[i]=rand()%100+1;
        scanf("%d", &array[i]);
    }
    //get max number
    for (int i = 0; i < 10; i++)
    {
        if (array[i] >= temp)
        {
            temp = array[i];
        }
    }
    //get max marks
    bool flag = false;
    for (int i = 0; i < 10; i++)
    {

        if (temp == array[i])
        {
            if (flag)
                k++;
            mark[k] = i;
            flag = true;
        }
    }

    for (int i = 0; i < 10; i++)
        printf("%d ", array[i]);
    printf("\n");

    printf("The max is %d. ", temp);
    printf("Mark ");
    for (int i = 0; i <= k; i++)
        printf("%d ", mark[i]);
    printf("\n");
}

void back_text()
{
    char text[100];
    bool flag = false;
    puts("Enter your text.");
    fgets(text, 100, stdin);
    int length = strlen(text) - 1;
    for (int i = 0; i <= length / 2; i++)
    {
        if (text[i] != text[length - 1 - i])
        {
            flag = true;
            break;
        }
    }
    if (flag)
        puts("no");
    else
        puts("yes");
}


#ifndef NUM
#define NUM 5
#endif

void find_item()
{
    srand((unsigned int) time(0));
    int array[NUM];
    int find;
    bool flag = false;
    for (int i = 0; i < NUM; i++)
    {
        //array[i]=rand()%10+1;
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < NUM; i++)
        printf("%d ", array[i]);

    puts("Enter the number you want to delete.");
    scanf("%d", &find);
    int length = NUM;
    for (int i = 0; i < length; i++)
    {
        if (array[i] == find)
        {
            flag = true;
            if (i != length - 1)
            {
                for (int j = i; j <= length - 1; j++)
                {
                    array[j] = array[j + 1];
                }
                i--;
            }
            length--;
        }
    }

    if (length == 0)
        puts("List empty.");
    else if (flag)
    {
        for (int i = 0; i < length; i++)
            printf("%d ", array[i]);
    }
    else
        puts("It's not in the list.");
}

#undef NUM