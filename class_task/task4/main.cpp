#include "stack.h"
#include <string.h>
#define NUM 500

void categories();

void big();  //change initial letter into big and ignore blankspaces

void x_to_d(); //16进制转10进制

void SquareNumber(); //完全平方数

void day_of_week(); //周末愉快

void romantic_number(); //亲密数
int sum_yinzi(int);

char *input(char *);
void words(); //单词匹配


int main()
{
    //categories();
    //big();
    //x_to_d();
    //SquareNumber();
    //day_of_week();
    //romantic_number();
    words();
    return 0;
}


void categories()
{
    char input[100];
    int letter = 0, blankspace = 0, number = 0, other = 0;
    puts("enter a series of char");
    fgets(input, 100, stdin);
    for (int i = 0; input[i] != '\n'; i++)
    {
        if (input[i] <= 'z' && input[i] >= 'A')
            letter++;
        else if (input[i] == ' ')
            blankspace++;
        else if (input[i] >= '0' && input[i] <= '9')
            number++;
        else
            other++;

    }
    printf("letter=%d\n", letter);
    printf("blankspace=%d\n", blankspace);
    printf("number=%d\n", number);
    printf("other=%d\n", other);
}

void big()
{
    puts("Enter a series of letters. (enter to stop)");
    char input, lastget = ' ';
    while ((input = getchar()) != '\n')
    {
        if (lastget == ' ' && input != ' ')
        {
            if (input >= 'Z')
                input -= 32;
            putchar(input);
        }
        else if (lastget != ' ' && input != ' ')
            putchar(input);
        lastget = input;
    }
    printf("\n");
}

void x_to_d()
{
    SqStack S;
    int input, temp;
    InitStack(&S);
    puts("Enter a number begins with 0x");
    scanf("%x", &input);
    while (input)
    {
        Push(&S, input % 10);
        input /= 10;
    }
    while (!StackEmpty(&S))
    {
        temp = Pop(&S);
        printf("%d", temp);
    }
    puts("");
}

void SquareNumber()
{
    int answer;
    for (int i = 2; (answer = i * i) <= 1000; i++)
    {
        printf("%d", answer);
        if ((i - 1) % 8 == 0)
            printf("\n");
        else
            printf("\t");
    }
}

void day_of_week()
{
    int day;
    puts("Please enter a number between 1 and 7.");
    while (true)
    {
        scanf("%d", &day);
        if (day >= 1 && day <= 7)
            break;
        puts("Please enter a number between 1 and 7.");
    }
    switch (day)
    {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            puts("Happy workday!");
            break;
        case 6:
        case 7:
            puts("Happy weekends!");
            break;
        default:
            puts("Error.");
            break;
    }
}

void romantic_number()
{
    int number1,number2,sum=0;
    for(int i=1; i<500; i++)
    {
        number1=sum_yinzi(i);
        for(int j=i;j<500;j++)
        {
            number2=sum_yinzi(j);
            if(number1==j && number2==i)
            {
                printf("(%d,%d)\n", i, j);
                sum += i+j;
            }
        }
    }
    printf("The sum is %d.\n",sum);
}

int sum_yinzi(int number)
{
    int sum=0;
    for(int i=1;i<number;i++)
    {
        if(number%i==0)
            sum += i;
    }
    return sum;
}

char *input(char *text) //get the text
{
    char *find, *get;
    get = fgets(text, NUM, stdin);
    if (get)
    {
        find = strchr(text, '\n');
        if (find)
        {
            *find = '\0'; //use '\0' to replace '\n'
        }
        else
            while (getchar() != '\n');  //Clean keyboard cache
    }
    return get;
}

void words()
{
    char text[NUM];
    puts("Enter a sentence.");
    input(text);
    int words = 0;
    bool flag = false;
    for (int i = 0; i < NUM && text[i] != '\0'; i++)
    {
        if (text[i] == ' ' || text[i] == '.' || text[i] == ',' || text[i] == ';')
        {
            if ((text[i] == ',' && text[i + 1] == ' ') || (text[i] == '.' && text[i + 1] == ' '))
            {
                flag = true;  //To avoid ',' and space add repeatedly
            }
            words++;
            if (flag)
            {
                words--;
                flag = false;
            }
        }
    }
    printf("words=%d\n", words);
}