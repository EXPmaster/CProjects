#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 45
//²âÊÔÁ´±í
struct film
{
    char title[MAX];
    int rating;
    struct film *next;
};

char *s_gets(char *st, int n);

int main()
{
    struct film *head = NULL;
    struct film *previous, *current;
    char input[MAX];
    //get information
    printf("Enter first movie tittle:\n");
    while (s_gets(input, MAX) != NULL && input[0] != '\0')
    {
        current = (struct film *) malloc(sizeof(struct film));
        if (head == NULL)
            head = current;
        else
            previous->next = current;
        current->next = NULL;
        strcpy(current->title, input);
        printf("Enter the rating<0=10>:\n");
        scanf("%d", &current->rating);
        while (getchar() != '\n')
            continue;
        printf("Enter the movie tittle(empty line to stop):\n");
        previous = current;
    }
    //show list
    if (head == NULL)
        printf("No data entered. ");
    else
        printf("Here is the movie list:\n");
    current = head;
    while (current != NULL)
    {
        printf("Movie: %s\tRating: %d\n",
               current->title, current->rating);
        current = current->next;
    }

    //free space
    current = head;
    while (current != NULL)
    {
        free(current);
        current = current->next;
    }
    printf("That's the end.\n");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *get;
    char *find;
    get = fgets(st, n, stdin);
    if (get)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return get;
}