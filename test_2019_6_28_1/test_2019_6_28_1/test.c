#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "Slist.h"
#include <stdlib.h>
void menu()
{
	printf("**  1.β������             2.β��ɾ��               **\n");
	printf("**  3.ͷ������             4.ͷ��ɾ��               **\n");
	printf("**  5.����λ�ò���         6.����λ��ɾ��           **\n");
	printf("**  7.ͳ�ƽڵ����         8.���ص�һ��ֵ           **\n");
	printf("**  9.�������һ��ֵ       10.��ʾ                  **\n");
	printf("**  11.�ͷ�                12.�ÿ�                  **\n");
	printf("**  13.����                14.ɾ��ָ��������ֵ      **\n");
	printf("**  15.ɾ��ָ��������ֵ�ڶ��ַ���                   **\n");
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
			printf("������Ҫ�����ĸ�������:");
			scanf("%d", &val);
			printf("������������:");
			scanf("%d", &data);
			SListInsertAfter(SListFind(&pl, val),data);
			break;
		case 6:
			printf("������Ҫɾ������:");
			scanf("%d", &val);
			SListErase(&pl, SListFind(&pl, val));
			break;
		case 7:
			count=SListSize(&pl);
			printf("�ڵ����Ϊ:%d\n", count);
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
			printf("������Ҫɾ����ֵ:");
			scanf("%d", &data);
			removeElement2(&pl, data);//ɾ������Ϊdata��ֵ
			break;
		case 15:
			printf("������Ҫɾ����ֵ:");
			scanf("%d", &data);
			removeElements(&pl, data);//ɾ������Ϊdata��ֵ
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
//	/*printf("������Ҫ�������:");
//	scanf("%d", &data);*/
//	SListPushBack2(&PH, 1);
//	/*printf("������Ҫ�������:");
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