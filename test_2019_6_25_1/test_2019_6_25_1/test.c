#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include <stdlib.h>
#include <stdio.h>
void menu()
{
	printf("****************************\n");
	printf("**1.PushBack    2.PopBack **\n");
	printf("**3.PushFront   4.PopFront**\n");
	printf("**5.Insert      6.Erase   **\n");
	printf("**7.Find        8.Print   **\n");
	printf("**        9.Destroy       **\n");
	
}
void test()
{
	SeqList s;
	SeqListInit(&s);
	int input = 0;
	do
	{
		menu();
		printf("ÇëÑ¡Ôñ:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			SeqListPushBack(&s,1);
			SeqListPushBack(&s,2);
			SeqListPushBack(&s,3);
			break;
		case 2:
			SeqListPopBack(&s);
			break;
		case 3:
			SeqListPushFront(&s,4);
			break;
		case 4:
			SeqListPopFront(&s);
			break;
		case 5:
			SeqListInsert(&s,2,6);
			break;
		case 6:
			SeqListErase(&s, 2);
			break;
		case 7:
			SeqListFind(&s, 2);
			break;
		case 8:
			PrintSeqList(&s);
			break;
		case 9:
			SeqListDestroy(&s);
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