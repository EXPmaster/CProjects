//
// Created by Leo on 2018/11/18.
//

#ifndef TASK6_LIST_H
#define TASK6_LIST_H

#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 1
#define LIST_MAX_SIZE 100

typedef int Elemtype;

typedef struct LNode
{
    Elemtype data;
    struct LNode *next;
} *Link;

typedef struct
{
    Link head, tail;
    int len;
} LinkList;

void InitList(LinkList *L);
void Addto(LinkList *L, Elemtype element); //add to next
void DestroyList(LinkList *L); //destroy the list and free the memory
void ListInsert(LinkList *L, int i, Elemtype element); //insert element to certain place
void ListDelete(LinkList *L, int i);  //delete an element of certain location
void TraversalList(LinkList *L);  //show the list
void ReverseList(LinkList *L); //reverse list
void SetElem(LinkList *L, int i, Elemtype element); //change certain element data
void GetElem();

void InitList(LinkList *L)
{
    L->head = (Link) malloc(sizeof(LNode));
    if (!L->head)
    {
        puts("Initialize failed.");
        exit(0);
    }
    L->tail = L->head;
    L->head->next = NULL;
    L->len = LIST_INIT_SIZE;
    L->head->data = LIST_MAX_SIZE;
}

void Addto(LinkList *L, Elemtype element)
{
    Link p = (Link) malloc(sizeof(LNode));
    L->tail->next = p;
    p->data = element;
    L->tail = p;
    p->next = NULL;
    L->len++;
}

void DestroyList(LinkList *L)
{
    L->tail = L->head;
    while (L->tail)
    {
        L->tail = L->head->next;
        free(L->head);
        L->head = L->tail;
    }
    L->len = 0;
    puts("Destroy finished.");
}

void ListInsert(LinkList *L, int i, Elemtype element)
{
    if (i > L->len || i <= 0)
    {
        puts("Overflow.");
        exit(0);
    }
    Link previous = L->head;
    for (int k = 1; k < i; k++, previous = previous->next);
    Link current = (Link) malloc(sizeof(LNode));
    current->next = previous->next;
    previous->next = current;
    current->data = element;
    L->len++;
}

void ListDelete(LinkList *L, int i)
{
    if (i > L->len || i <= 0)
    {
        puts("Overflow.");
        exit(0);
    }
    Link previous, current = L->head;
    for (int k = 1; k <= i; k++, previous = current, current = current->next);
    previous->next = current->next;
    L->len--;
    free(current);
}

void TraversalList(LinkList *L)
{
    Link current = L->head->next;
    printf("The list has %d element.\n", L->len);
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void ReverseList(LinkList *L)
{
    if (L->head->next == NULL || L->head->next->next == NULL)
        return;
    Link current = L->head->next, previous = L->head, over;
    while (current)
    {
        over = current->next;
        current->next = previous;
        previous = current;
        current = over;
    }
    L->head->next->next = NULL;
    L->tail = L->head->next;
    L->head->next = previous;
}

void SetElem(LinkList *L, int i, Elemtype element)
{
    if (i > L->len || i <= 0)
    {
        puts("Overflow.");
        exit(0);
    }
    Link current = L->head;
    for (int k = 1; k <= i; k++, current = current->next);
    current->data = element;
}

#endif //TASK6_LIST_H
