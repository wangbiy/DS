#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include <stdlib.h>
void menu()
{
	printf("***********************************************\n");
	printf("**  1.压栈           2.出栈                  **\n");
	printf("**  3.获取栈顶元素   4.获取栈内有效元素个数  **\n");
	printf("**  5.清空           6.销毁                  **\n");
}
void test()
{
	Stack s;
	int input = 0;
	STDataType data = 0;
	StackInit(&s);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入要入栈的数:");
			scanf("%d", &data);
			StackPush(&s, data);
			break;
		case 2:
			StackPop(&s);
			break;
		case 3:
			data=StackTop(&s);
			printf("栈顶元素为:%d\n", data);
			break;
		case 4:
			data=StackSize(&s);
			printf("有效元素个数为:%d\n", data);
			break; 
		case 5:
			StackEmpty(&s);
			break;
		case 6:StackDestroy(&s);
			break;
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}