#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
#include <stdio.h>
#include <stdlib.h>
void menu()
{
	printf("**1.β��             2.βɾ            **\n");
	printf("**3.ͷ��             4.ͷɾ            **\n");
	printf("**5.����λ�ò���     6.����λ��ɾ��    **\n");
	printf("**7.���ص�һ��Ԫ��   8.�������һ��Ԫ��**\n");
	printf("**9.��ӡ             10.�ÿ�           **\n");
	printf("**11.�ͷ�            12.�˳�           **\n");
	
}
void test()
{
	int input = 0;
	DLDataType data=0;
	DLNode *PH=NULL;
	DListInit(&PH);
	do
	{
		menu();
		printf("��ѡ��;>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������Ҫ�������:");
			scanf("%d", &data);
			DListPushBack(PH, data);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			PrintDList(PH);
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