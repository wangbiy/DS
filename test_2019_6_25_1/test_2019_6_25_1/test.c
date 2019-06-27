#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <stdlib.h>
#include <stdio.h>
void menu()
{
	printf("**  1.β������             2.β��ɾ��               **\n");
	printf("**  3.ͷ������             4.ͷ��ɾ��               **\n");
	printf("**  5.����λ�ò���         6.����λ��ɾ��           **\n");
	printf("**  7.����                 8.��������               **\n");
	printf("**  9.������Чֵ           10.���ص�һ��ֵ          **\n");
	printf("**  11.�������һ��ֵ      12.�Ƴ�һ��Ϊdata��ֵ    **\n");
	printf("**  13.�Ƴ�Ϊdata������ֵ  14.��ʾ                  **\n");
	printf("**  15.�ͷ�                16.�ÿ�                  **\n");
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ҫ�������:");
			scanf("%d", &data);
			SeqListPushBack(&s, data);
			break;
		case 2:
			SeqListPopBack(&s);
			break;
		case 3:
			printf("������Ҫ�������:");
			scanf("%d", &data);
			SeqListPushFront(&s, data);
			break;
		case 4:
			SeqListPopFront(&s);
			break;
		case 5:
			printf("������Ҫ�����λ��:");
			scanf("%d", &pos);
			printf("������Ҫ�������:");
			scanf("%d", &data);
			SeqListInsert(&s, pos, data);
			break;
		case 6:
			printf("������Ҫɾ��ֵ��λ��:");
			scanf("%d", &pos);
			SeqListErase(&s, pos);
			break;
		case 7:
			printf("������Ҫ���ҵ���:");
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
			printf("������Ҫ�Ƴ���ֵ:");
			scanf("%d", &data);
			SeqListRemove(&s, data);
			break;
		case 13:
			printf("������Ҫ�Ƴ���ֵ:");
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