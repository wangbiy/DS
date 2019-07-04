#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
#include <stdio.h>
#include <stdlib.h>
void menu()
{
	printf("**1.尾插             2.尾删            **\n");
	printf("**3.头插             4.头删            **\n");
	printf("**5.任意位置插入     6.任意位置删除    **\n");
	printf("**7.返回第一个元素   8.返回最后一个元素**\n");
	printf("**9.打印             10.置空           **\n");
	printf("**11.释放            12.退出           **\n");
	
}
void test()
{
	int input = 0;
	DLDataType data=0;
	DLNode *PH=NULL;
	DLDataType val = 0;
	DListInit(&PH);
	do
	{
		menu();
		printf("请选择;>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入要插入的数:");
			scanf("%d", &data);
			DListPushBack(PH, data);
			break;
		case 2:
			DListPopBack(PH);
			break;
		case 3:
			printf("请输入要插入的数:");
			scanf("%d", &data);
			DListPushFront(PH, data);
			break;
		case 4:
			DListPopFront(PH);
			break;
		case 5:
			printf("请输入要插入的位置:");
			scanf("%d", &val);
			printf("请输入要插入的值:");
			scanf("%d", &data);
			DListInsertFront(DListFind(PH, val), data);
			break;
		case 6:
			printf("请输入要删除的数的位置:");
			scanf("%d", &val);
			DListErase(DListFind(PH, val));
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			PrintDList(PH);
			break;
		case 10:
			break;
		case 11:
			DListDestroy(&PH);
			break;
		case 12:
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