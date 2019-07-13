//括号匹配问题，栈的实现
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
typedef int STDataType;
typedef struct Stack
{
	STDataType* arr;
	int top;//标记栈顶，相当于顺序表中的size
	int capacity;
}Stack;
void StackInit(Stack* s)
{
	assert(s);
	s->arr = (STDataType*)malloc(sizeof(STDataType)* 3);
	if (NULL == s->arr)
	{
		assert(0);
		return;
	}
	s->capacity = 3;
	s->top = 0;
}
void CheckCapacity(Stack *s)
{
	assert(s);
	if (s->top == s->capacity)
	{
		int NewCapacity = s->capacity * 2;
		STDataType* temp = (STDataType*)malloc(sizeof(STDataType)*NewCapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		memcpy(temp, s->arr, s->top*sizeof(STDataType));
		free(s->arr);
		s->arr = temp;
		s->capacity = NewCapacity;
	}
}
void StackPush(Stack *s, STDataType data)
{
	assert(s);
	CheckCapacity(s);//扩容
	s->arr[s->top] = data;
	s->top++;
}
void StackPop(Stack *s)
{
	assert(s);
	if (0 == s->top)//栈存在但是栈顶没有元素
		return;
	s->top--;
}
STDataType StackTop(Stack *s)//获取栈顶元素
{
	assert(s);
	return s->arr[s->top - 1];
}
int StackSize(Stack *s)//获取栈内有效元素个数
{
	assert(s);
	return s->top;
}
int StackEmpty(Stack *s)
{
	assert(s);
	return 0 == s->top;
}
void StackDestroy(Stack *s)
{
	assert(s);
	if (s->arr)
	{
		free(s->arr);
		s->arr = NULL;
		s->capacity = 0;
		s->top = 0;
	}
}
bool isValid(char* s){
	int len = 0;
	Stack st;
	bool ret = false;
	int i = 0;
	if (NULL == s)
		return false;
	StackInit(&st);
	len = strlen(s);
	for (; i < len; i++)
	{
		if ('(' == s[i] || '[' == s[i] || '{' == s[i])
		{
			//入栈
			StackPush(&st, s[i]);

		}
		else//当前为右括号
		{
			char ch;
			if (StackEmpty(&st))
				break;
			ch = StackTop(&st);
			if (('(' == ch&&')' == s[i]) ||
				('[' == ch&&']' == s[i]) ||
				('{' == ch&&'}' == s[i]))
				StackPop(&st);
			else
			{
				break;
			}
		}

	}
	if (i == len&&StackEmpty(&st))
		ret = true;
	StackDestroy(&st);
	return ret;
}
int main()
{
	char s[] = "{[()]}";
	isValid(s);
	system("pause");
	return 0;
}

