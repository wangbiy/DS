#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <stdlib.h>
#include <stdio.h>
void menu()
{
	printf("**  1.尾部插入             2.尾部删除               **\n");
	printf("**  3.头部插入             4.头部删除               **\n");
	printf("**  5.任意位置插入         6.任意位置删除           **\n");
	printf("**  7.查找                 8.返回容量               **\n");
	printf("**  9.返回有效值           10.返回第一个值          **\n");
	printf("**  11.返回最后一个值      12.移除一个为data的值    **\n");
	printf("**  13.移除为data的所有值  14.显示                  **\n");
	printf("**  15.释放                16.置空                  **\n");
}
void test()
{
	SeqList s;
	SeqListInit(&s);
	int input = 0;
	DataType data = 0;
	int pos = 0;
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
			SeqListPushBack(&s, data);
			break;
		case 2:
			SeqListPopBack(&s);
			break;
		case 3:
			printf("请输入要插入的数:");
			scanf("%d", &data);
			SeqListPushFront(&s, data);
			break;
		case 4:
			SeqListPopFront(&s);
			break;
		case 5:
			printf("请输入要插入的位置:");
			scanf("%d", &pos);
			printf("请输入要插入的数:");
			scanf("%d", &data);
			SeqListInsert(&s, pos, data);
			break;
		case 6:
			printf("请输入要删除值的位置:");
			scanf("%d", &pos);
			SeqListErase(&s, pos);
			break;
		case 7:
			printf("请输入要查找的数:");
			scanf("%d", &data);
			SeqListFind(&s, data);
			break;
		case 8:
			SeqListCapacity(&s);
			break;
		case 9:
			SeqListSize(&s);
			break;
		case 10:
			SeqListFront(&s);
			break;
		case 11:
			SeqlistBack(&s);
			break;
		case 12:
			printf("请输入要移除的值:");
			scanf("%d", &data);
			SeqListRemove(&s, data);
			break;
		case 13:
			printf("请输入要移除的值:");
			scanf("%d", &data);
			SeqListRemoveAll(&s, data);
			break;
		case 14:
			PrintSeqList(&s);
			break;
		case 15:
			SeqListDestroy(&s);
			break;
		case 16:
			SeqListEmpty(&s);
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