#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Slist.h"
#include <stdlib.h>
void menu()
{
	printf("**  1.尾部插入             2.尾部删除               **\n");
	printf("**  3.头部插入             4.头部删除               **\n");
	printf("**  5.任意位置插入         6.任意位置删除           **\n");
	printf("**  7.统计节点个数         8.返回第一个值           **\n");
	printf("**  9.返回最后一个值       10.显示                  **\n");
	printf("**  11释放                 12.置空                  **\n");
}
void test()
{
	SList pl;
	SListInit(&pl);
	int input = 0;
	Node *pos;
	SDataType data;
	SDataType val;
	int count = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入要插入的数:");
			scanf("%d", &data);
			SListPushBack(&pl, data);
			break;
		case 2:
			SListPopBack(&pl);
			break;
		case 3:
			printf("请输入要插入的数:");
			scanf("%d", &data);
			SListPushFront(&pl, data);
			break;
		case 4:
			SListPopFront(&pl);
			break;
		case 5:
			printf("请输入要插入哪个数后面:");
			scanf("%d", &val);
			printf("请输入插入的数:");
			scanf("%d", &data);
			SListInsertAfter(SListFind(&pl, val),data);
			break;
		case 6:
			printf("请输入要删除的数:");
			scanf("%d", &val);
			SListErase(&pl, SListFind(&pl, val));
			break;
		case 7:
			count=SListSize(&pl);
			printf("节点个数为:%d\n", count);
			break;
		case 8:
			SListFront(&pl);
			break;
		case 9:
			SListBack(&pl);
			break;
		case 10:
			PrintSList(&pl);
			break;
		case 11:
			SListDestroy(&pl);
			break;
		case 12:
			SListEmpty(&pl);
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