#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Slist.h"
#include <stdlib.h>
void menu()
{
	printf("**  1.β������             2.β��ɾ��               **\n");
	printf("**  3.ͷ������             4.ͷ��ɾ��               **\n");
	printf("**  5.����λ�ò���         6.����λ��ɾ��           **\n");
	printf("**  7.����                 8.ͳ�ƽڵ����           **\n");
	printf("**  9.���ص�һ��ֵ         10.�������һ��ֵ        **\n");
	printf("**  11.��ʾ                12.�ͷ�                  **\n");
	printf("**  13.�ÿ�                                         **\n");
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ҫ�������:");
			scanf("%d", &data);
			SListPushBack(&pl, data);
			break;
		case 2:
			SListPopBack(&pl);
			break;
		case 3:
			printf("������Ҫ�������:");
			scanf("%d", &data);
			SListPushFront(&pl, data);
			break;
		case 4:
			SListPopFront(&pl);
			break;
		case 5:
			printf("������Ҫ�����λ��:");
			scanf("%d", &pos);
			printf("������Ҫ�������:");
			scanf("%d", &data);
			SListInsertAfter(&pos, data);
			break;
		case 6:
			printf("������Ҫɾ��������λ��:");
			scanf("%d", &pos);
			SListErase(&pl, &pos);
			break;
		case 7:
			printf("������Ҫ���ҵ���:");
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