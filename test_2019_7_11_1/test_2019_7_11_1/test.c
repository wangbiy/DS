#define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include <stdlib.h>
void menu()
{
	printf("***********************************************\n");
	printf("**  1.ѹջ           2.��ջ                  **\n");
	printf("**  3.��ȡջ��Ԫ��   4.��ȡջ����ЧԪ�ظ���  **\n");
	printf("**  5.���           6.����                  **\n");
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ҫ��ջ����:");
			scanf("%d", &data);
			StackPush(&s, data);
			break;
		case 2:
			StackPop(&s);
			break;
		case 3:
			data=StackTop(&s);
			printf("ջ��Ԫ��Ϊ:%d\n", data);
			break;
		case 4:
			data=StackSize(&s);
			printf("��ЧԪ�ظ���Ϊ:%d\n", data);
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