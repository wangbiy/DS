#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Slist.h"
#include <stdlib.h>
void menu()
{
	printf("**  1.尾部插入             2.尾部删除               **\n");
	printf("**  3.头部插入             4.头部删除               **\n");
	printf("**  5.任意位置插入         6.任意位置删除           **\n");
	printf("**  7.查找                 8.统计节点个数           **\n");
	printf("**  9.返回第一个值         10.返回最后一个值        **\n");
	printf("**  11.显示                12.释放                  **\n");
	printf("**  13.置空                                         **\n");
}
void test()
{
	SList pl;
	SListInit(&pl);
	int input = 0;
	Node *pos;
	SDataType data;
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
			printf("请输入要插入的位置:");
			scanf("%d", &pos);
			printf("请输入要插入的数:");
			scanf("%d", &data);
			SListInsertAfter(&pos, data);
			break;
		case 6:
			printf("请输入要删除的数的位置:");
			scanf("%d", &pos);
			SListErase(&pl, &pos);
			break;
		case 7:
			printf("请输入要查找的数:");
			scanf("%d", &data);
			SListFind(&pl, data);
			break;
		case 8:
			SListSize(&pl);
			break;
		case 9:
			SListFront(&pl);
			break;
		case 10:
			SListBack(&pl);
			break;
		case 11:
			PrintSList(&pl);
			break;
		case 12:
			SListDestroy(&pl);
			break;
		case 13:
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