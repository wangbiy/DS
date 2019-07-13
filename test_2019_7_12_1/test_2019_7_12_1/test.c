#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
void menu()
{
	printf("***************************************\n");
	printf("**1.���              2.����         **\n");
	printf("**3.��ȡ��ͷԪ��      4.��ȡ��βԪ�� **\n");
	printf("**5.��ȡ��ЧԪ�ظ���  6.�ÿ�         **\n");
	printf("**7.����              8.��ʾ         **\n");
	printf("***************************************\n");
}
void test()
{
	int input = 0;
	Queue q;
	QUDataType data = 0;
	QueueInit(&q);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ҫ��ӵ�Ԫ��:");
			scanf("%d", &data);
			QueuePush(&q, data);
			break;
		case 2:
			QueuePop(&q);
			break;
		case 3:
			data=QueueFront(&q);
			printf("��ͷԪ��Ϊ:%d\n", data);
			break;
		case 4:
			data = QueueBack(&q);
			printf("��βԪ��Ϊ:%d\n", data);
			break;
		case 5:
			data=QueueSize(&q);
			printf("��ЧԪ�ظ���Ϊ:%d\n", data);
			break;
		case 6:
			Queuempty(&q);
			break;
		case 7:
			QueueDestroy(&q);
			break;
		case 8:
			QueueShow(&q);
			break;
		default:
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