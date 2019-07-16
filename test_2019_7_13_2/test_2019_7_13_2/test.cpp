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
//C语言实现
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
//c++实现括号匹配问题
//class solution{
//public:
//	bool isValid(string s){
//		std::stack<char> str;
//		int size = s.size();
//		for (int i = 0; i < size; i++)
//		{
//			char ch = s[i];
//			switch (ch)
//			{
//			case'(':
//			case'[':
//			case'{':
//				str.push(ch);
//				break;
//			case')':
//			case']':
//			case'}':
//			{
//					   if (str.empty())
//						   return false;
//					   else
//					   {
//						   char left = str.top();
//						   str.pop();
//						   if (!((left == '('&&ch == ')') || (left == '['&&ch == ']') || (left == '{'&& ch == '}')))
//						   {
//							   return false;
//						   }
//					   }
//					   break;
//			}
//			}
//		}
//		if (!str.empty())
//			return false;
//		return true;
//	}
//};
//用队列实现栈
#include <queue>
class MyStack {
	std::queue<int> q;
public:
	MyStack() {
	}
	void push(int x) {
		q.push(x);

	}
	int pop() {
		int n = q.size();
		for (int i = 0; i<n - 1; i++)
		{
			int v = q.front();
			q.pop();
			q.push(v);
		}
		int v = q.front();
		q.pop();
		return v;
	}
	int top() {
		int n = q.size();
		for (int i = 0; i<n - 1; i++)
		{
			int v = q.front();
			q.pop();
			q.push(v);
		}
		int v = q.front();
		q.pop();
		q.push(v);
		return v;
	}
	bool empty() {
		return q.empty();
	}
};
//用栈实现队列
#include <stack>
class MyQueue {
	std::stack<int> in;
	std::stack<int> out;
public:
	MyQueue() {

	}
	void push(int x) {
		in.push(x);

	}
	int pop() {
		if (out.empty())
		{
			int n = in.size();
			for (int i = 0; i<n; i++)
			{
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}
		int v = out.top();
		out.pop();
		return v;
	}
	int peek() {
		if (out.empty())
		{
			int n = in.size();
			for (int i = 0; i<n; i++)
			{
				int v = in.top();
				in.pop();
				out.push(v);
			}
		}
		int v = out.top();
		return v;
	}
	bool empty() {

		return in.empty() && out.empty();
	}
};
//实现最小栈
class MinStack {
	std::stack<int> nomal;
	std::stack<int> min;
public:
	MinStack() {

	}
	void push(int x) {
		nomal.push(x);
		if (min.empty() || x <= min.top())
		{
			min.push(x);
		}
		else
		{
			min.push(min.top());
		}
	}
	void pop() {
		nomal.pop();
		min.pop();
	}
	int top() {
		return nomal.top();
	}
	int getMin() {
		return min.top();
	}
};
//循环队列
class MyCircularQueue{
	int* arr;
	int front;
	int rear;
	int size;
	int capacity;
public:
	MyCircularQueue(int k)//初始化
	{
		arr = (int*)malloc(sizeof(int)*k);
		capacity = k;
		size = 0;
		front = 0;
		rear = 0;
	}
	bool enQueue(int value)
	{
		if (size >= capacity)
		{
			return false;
		}
		arr[rear] = value;
		rear = (rear + 1) % capacity;
		size++;
		return true;
	}
	bool deQueue()
	{
		if (size == 0)
			return false;
		front = (front + 1) % capacity;
		size--;
		return true;
	}
	int Queuefront()
	{
		if (size == 0)
			return -1;
		return arr[front];
	}
	int Rear()
	{
		if (size == 0)
			return -1;
		int index = (rear + capacity - 1) % capacity;
		return arr[index];
	}
	bool isEmpty()
	{
		return size == 0;
	}
	bool isFull()
	{
		return size == capacity;
	}
};
int main()
{
	char s[] = "{[()]}";
	isValid(s);
	system("pause");
	return 0;
}

