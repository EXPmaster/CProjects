//
// Created by Leo on 2018/11/14.
//

#ifndef TASK7_STACK_STACK_H
#define TASK7_STACK_STACK_H

#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 100 //origin size of the stack
#define ADD_SIZE 10 //add size of the stack

typedef int Elemtype; //The type of elements in the stack is changeable

typedef struct stack
{
    Elemtype *base;
    Elemtype *top;
    int stacksize; //the total size of the stack
} SqStack;


void InitStack(SqStack *S); //initialize stack

Elemtype GetTop(SqStack *S, Elemtype element);  //get an element from the top of the stack

void Push(SqStack *S, Elemtype element); //push an element to the top of the stack

void Pop(SqStack *S, Elemtype *element); //delete an element from the top of the stack

void ClearStack(SqStack *S);  //clear all elements of the stack

void TraversalStack(SqStack *S); //print all elements of the stack

int GetLength(SqStack *S);  //get the length of the stack

bool StackEmpty(SqStack *S); //true is empty, false is not


void InitStack(SqStack *S)
{
    S->base = (Elemtype *) malloc(STACK_SIZE * sizeof(Elemtype));  //allocate memory for the stack
    if (!S->base)
        exit(0); //allocate memory unsuccessfully
    S->top = S->base;
    S->stacksize = STACK_SIZE;
}

Elemtype GetTop(SqStack *S, Elemtype element)
{
    if (S->base == S->top)
    {
        puts("Stack is empty.");
        return 0;
    }
    else
    {
        element = *(S->top - 1);
    }
    return element;
}

void Push(SqStack *S, Elemtype element)
{
    if (S->top - S->base >= S->stacksize)
    {
        S->base = (Elemtype *) realloc(S->base, (S->stacksize + ADD_SIZE) * sizeof(Elemtype)); //allocate larger memory
        if (!S->base)
            exit(0); //allocate memory unsuccessfully
        S->top = S->base + S->stacksize;
        S->stacksize += ADD_SIZE;
    }
    *S->top++ = element;
}

void Pop(SqStack *S, Elemtype *element)
{
    if (S->top == S->base)
        exit(0);  //empty
    *element = *--S->top; //get the element under top, and top-1
}

void ClearStack(SqStack *S)
{
    if (S->base != S->top)
    {
        S->top = S->base;
        puts("Stack is empty now.");
    }
}

void DestroyStack(SqStack *S)
{
    if (S->base)
    {
        free(S->base);
        S->base = NULL;
        S->top = NULL;
        S->stacksize = 0;
        puts("Stack destroyed successfully.");
    }
}

int GetLength(SqStack *S)
{
    Elemtype *q = S->top;
    int i = 0;
    if (S->base)
        for (; q != S->base; i++, q--);
    return i;
}

void TraversalStack(SqStack *S)
{
    for (int i = 0; i < GetLength(S); i++)
        printf("Element %d is %d\n", i+1, S->base[i]);
}

bool StackEmpty(SqStack *S)
{
    return (S->base == S->top);
}

#endif //TASK7_STACK_STACK_H