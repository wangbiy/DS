#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <stdlib.h>
#include <stdio.h>
void test()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	PrintSeqList(&s);

	SeqListPopBack(&s);
	PrintSeqList(&s);

	SeqListPushFront(&s, 4);
	PrintSeqList(&s);

	SeqListPopFront(&s);
	PrintSeqList(&s);

	SeqListInsert(&s, 2, 6);
	PrintSeqList(&s);

	SeqListErase(&s, 2);
	PrintSeqList(&s);

	SeqListFind(&s, 2);
	SeqListDestroy(&s);
}
int main()
{
	test();
	system("pause");
	return 0;
}