#ifndef CLASS_TASK4_STACK_H
#define CLASS_TASK4_STACK_H

#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 50//origin size of the stack
#define ADD_SIZE 10 //add size of the stack

typedef int Elemtype; //The type of elements in the stack is changeable

typedef struct stack
{
    Elemtype *base;
    Elemtype *top;
    int stacksize; //the total size of the stack
} SqStack;


void InitStack(SqStack *S); //initialize stack

void Push(SqStack *S, Elemtype element); //push an element to the top of the stack

Elemtype Pop(SqStack *S); //delete an element from the top of the stack

bool StackEmpty(SqStack *S); //true is empty, false is not


void InitStack(SqStack *S)
{
    S->base = (Elemtype *) malloc(STACK_SIZE * sizeof(Elemtype));  //allocate memory for the stack
    if (!S->base)
        exit(0); //allocate memory unsuccessfully
    S->top = S->base;
    S->stacksize = STACK_SIZE;
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

Elemtype Pop(SqStack *S)
{
    Elemtype element;
    if (S->top == S->base)
        exit(0);  //empty
    element = *--S->top; //get the element under top, and top-1
    return element;
}

bool StackEmpty(SqStack *S)
{
    return (S->base == S->top);
}

#endif //CLASS_TASK4_STACK_H