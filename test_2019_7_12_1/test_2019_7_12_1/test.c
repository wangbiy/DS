#define _CRT_SECURE_NO_WARNINGS 1
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
void menu()
{
	printf("***************************************\n");
	printf("**1.入队              2.出队         **\n");
	printf("**3.获取队头元素      4.获取队尾元素 **\n");
	printf("**5.获取有效元素个数  6.置空         **\n");
	printf("**7.销毁              8.显示         **\n");
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
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入要入队的元素:");
			scanf("%d", &data);
			QueuePush(&q, data);
			break;
		case 2:
			QueuePop(&q);
			break;
		case 3:
			data=QueueFront(&q);
			printf("队头元素为:%d\n", data);
			break;
		case 4:
			data = QueueBack(&q);
			printf("队尾元素为:%d\n", data);
			break;
		case 5:
			data=QueueSize(&q);
			printf("有效元素个数为:%d\n", data);
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