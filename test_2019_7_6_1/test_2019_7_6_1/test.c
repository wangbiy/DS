#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//编写代码，以给定值x为基准将链表分割成两部分，
//所有小于x的结点排在大于或等于x的结点之前 。
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
			//尾插到small链表中
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
			smallLast = cur;//因为之前的最后一个结点是插入的，用smalllast记录
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