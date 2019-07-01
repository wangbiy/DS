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
	printf("**  11.释放                12.置空                  **\n");
	printf("**  13.逆置                14.删除指定的所有值      **\n");
	printf("**  15.删除指定的所有值第二种方法                   **\n");
}
void test()
{
	SList pl;
	SListInit(&pl);
	int input = 0;
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
		case 13:
			ReverseSList(&pl);
			break;
		case 14:
			printf("请输入要删除的值:");
			scanf("%d", &data);
			removeElement2(&pl, data);//删除所有为data的值
			break;
		case 15:
			printf("请输入要删除的值:");
			scanf("%d", &data);
			removeElements(&pl, data);//删除所有为data的值
			break;

		}
	} while (input);
}
//void test2()
//{
//	Node *PH=NULL;
//	SDataType data = 0;
//	Node nodeHead;
//	nodeHead._PNext = NULL;
//	/*printf("请输入要插入的数:");
//	scanf("%d", &data);*/
//	SListPushBack2(&PH, 1);
//	/*printf("请输入要插入的数:");
//	scanf("%d", &data);*/
//	SListPushFront2(&nodeHead, 2);
//}
int main()
{
	test();
	/*test2();*/
	system("pause");
	return 0;
}