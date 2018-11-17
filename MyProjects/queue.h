//
// Created by Leo on 2018/11/15.
//

#ifndef TASK7_STACK_QUEUE_H
#define TASK7_STACK_QUEUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;  //element type is changeable

typedef struct QNode
{
    Elemtype data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front; //the front of queue (output)
    QueuePtr rear;  //the end of queue (input)
} LinkQueue;

void InitQueue(LinkQueue *Q);

void DestroyQueue(LinkQueue *Q);

void EnQueue(LinkQueue *Q, Elemtype element); //insert a new element as the rear of queue

Elemtype DeQueue(LinkQueue *Q, Elemtype element);  //delete and print the front element

Elemtype GetFront(LinkQueue *Q, Elemtype element); //get the front element of queue but not delete

void ClearQueue(LinkQueue *Q); // clear all the elements in queue

void TraversalQueue(LinkQueue *Q);  //traverse all elements in queue

bool QueueEmpty(LinkQueue *Q); //judge if the queue is empty, true is empty, false is not



void InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
    if (!Q->front)
        exit(0);  //allocate memory unsuccessfully
    Q->front->next = NULL;
}

void DestroyQueue(LinkQueue *Q)
{
    while (Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    puts("Queue destroyed successfully.");
}

void EnQueue(LinkQueue *Q, Elemtype element)
{
    QueuePtr p;
    p = (QueuePtr) malloc(sizeof(QNode));
    if (!p)
        exit(0);
    p->data = element;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

Elemtype DeQueue(LinkQueue *Q, Elemtype element)
{
    if (Q->front == Q->rear)
    {
        puts("The queue is empty.");
        return 0;
    }
    QueuePtr p;
    p = Q->front->next;
    element = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return element;
}

Elemtype GetFront(LinkQueue *Q, Elemtype element)
{
    QueuePtr p;
    p=Q->front->next;
    element = p->data;
    return element;
}

void ClearQueue(LinkQueue *Q)
{
    if (Q->front != Q->rear)
    {
        Q->rear = Q->front;
        puts("Queue clear successfully.");
    }
}

void TraversalQueue(LinkQueue *Q)
{
    int i = 1;
    QueuePtr p;
    p = Q->front->next;
    while (p)
    {
        printf("the %d element in queue is %d\n", i, p->data);
        p = p->next;
        i++;
    }
}

bool QueueEmpty(LinkQueue *Q)
{
    return (Q->front == Q->rear);
}

#endif //TASK7_STACK_QUEUE_H
