#pragma once
#include <assert.h>
#include <stdio.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//标记栈顶，相当于顺序表中的size
	int capacity;
}Stack;
void StackInit(Stack* s);
void StackDestroy(Stack *s);
void StackPush(Stack *s,STDataType data);
void StackPop(Stack *s);
STDataType StackTop(Stack *s);
int StackEmpty(Stack *s);
int StackSize(Stack *s);