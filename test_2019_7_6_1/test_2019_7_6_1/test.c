#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�
//����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ ��
typedef struct ListNode
{
	int val;
	struct ListNode *next;
}Node;
Node* partition(Node* head, int x)
{
	Node* small = NULL;
	Node* big = NULL;
	Node* smallLast = NULL;
	Node* bigLast = NULL;
	Node* cur = head;
	while (cur!=NULL)
	{
		Node* next = cur->next;
		if (cur->val < x)
			//β�嵽small������
		{
			cur->next = NULL;
			if (small == NULL)
			{
				small = cur;
			}
			else
			{
				smallLast->next = cur;
			}
			smallLast = cur;//��Ϊ֮ǰ�����һ������ǲ���ģ���smalllast��¼
			cur = next;
		}
		else
		{
			cur->next = NULL;
			if (big == NULL)
			{
				big = cur;
			}
			else
			{
				bigLast->next = cur;
			}
			bigLast = cur;
			cur = next;
		}
	}
	if (small == NULL)
		return big;
	else
	{
		smallLast->next = big;
		return small;
	}
}
Node* createList()
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 9;
	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->val = 5;
	Node* n3 = (Node*)malloc(sizeof(Node));
	n3->val = 2;
	Node* n4 = (Node*)malloc(sizeof(Node));
	n4->val = 7;
	Node* n5 = (Node*)malloc(sizeof(Node));
	n5->val = 3;
	Node* n6 = (Node*)malloc(sizeof(Node));
	n6->val = 6;
	Node* n7 = (Node*)malloc(sizeof(Node));
	n7->val = 4;
	Node* n8 = (Node*)malloc(sizeof(Node));
	n8->val = 8;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = NULL;
	return n1;
}
void PrintList(Node* head)
{
	Node* cur = NULL;
	assert(head);
	cur = head;
	while (cur)
	{
		printf("%d---->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}
int main()
{
	Node* PH = createList();
	Node* ret=partition(PH, 5);
	PrintList(ret);
	system("pause");
	return 0;
}