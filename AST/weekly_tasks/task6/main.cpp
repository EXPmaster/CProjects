#include <stdio.h>
#include <stdlib.h>

typedef struct dataset
{
    int data;
    struct dataset *next;
} Node;

Node *GetList(Node *);

void ShowList(Node *);

void FreeList(Node *);

Node *TurnList(Node *);

int main()
{
    Node *head = NULL;
    head = GetList(head);
    //printf("The address is %p\t%p\n", head, head->next);
    ShowList(head);
    if(head)
    {
        head = TurnList(head);
        ShowList(head);
    }
    FreeList(head);
    return 0;
}

Node *GetList(Node *head)
{
    int temp;
    Node *previous, *current;
    printf("Enter your number:(enter 666 to stop)\n");
    while (scanf("%d", &temp) && temp != 666)
    {
        while (getchar() != '\n')
            continue;
        current = (Node *) malloc(sizeof(Node));
        if (head == NULL)
            head = current;
        else
            previous->next = current;
        current->next = NULL;
        current->data = temp;
        previous = current;
        printf("Enter your number:(enter 666 to stop)\n");
    }
    return head;
}

void ShowList(Node *current)
{
    if (current == NULL)
        printf("List empty.\n");
    else
        printf("The data you've entered is:\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

Node *TurnList(Node *head)
{
    if (head == NULL || head->next == NULL) {}
    else
    {
        Node *current = head->next, *previous = head, *after = NULL;
        while (current != NULL)
        {
            after = current->next;
            current->next = previous;
            previous = current;
            current = after;
        }
        head->next = NULL;
        head = previous;
    }
    return head;
}

void FreeList(Node *current)
{
    Node *head = NULL;
    while (current != NULL)
    {
        head = current->next;
        free(current);
        current = head;
    }
    if (head == NULL)
        printf("Clean finished successfully.\n");
    else
        printf("Clean fail.\n");
}
