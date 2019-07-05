#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
	int data;
	struct ListNode *next;
}Node;
Node* mergeTwoList(Node *s1, Node *s2)
{
	Node *ResultHead = NULL;
	Node *last = NULL;
	Node *c1 = s1;
	Node *c2 = s2;
	if (s1 == NULL)
		return s2;
	if (s2 == NULL)
		return s1;
	while (c1 != NULL&&c2 != NULL)
	{
		if (c1->data <= c2->data)
		{
			Node *next = c1->next;
			//将c1尾插到ResultHead
			c1->next = NULL;
			if (ResultHead == NULL)
			{
				ResultHead = c1;
			}
			else
			{
				last->next = c1;
			}
			last = c1;
			c1 = next;
		}
		else
		{
			Node *next = c2->next;
			//将c1尾插到ResultHead
			c2->next = NULL;
			if (ResultHead == NULL)
			{
				ResultHead = c2;
			}
			else
			{
				last->next = c2;
			}
			last = c2;
			c2 = next;
		}
	}
	if (c1 != NULL)
		last->next = c1;
	if (c2 != NULL)
		last->next=c2;
	return ResultHead;
}
Node* createList1()
{
	Node *n1 = (Node*)malloc(sizeof(Node));
	n1->data = 1;
	Node *n2 = (Node*)malloc(sizeof(Node));
	n2->data = 2;
	Node *n3 = (Node*)malloc(sizeof(Node));
	n3->data = 3;
	Node *n4 = (Node*)malloc(sizeof(Node));
	n4->data = 4;
	Node *n5 = (Node*)malloc(sizeof(Node));
	n5->data = 5;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	return n1;
}
Node* createList2()
{
	Node *n1 = (Node*)malloc(sizeof(Node));
	n1->data = 1;
	Node *n2 = (Node*)malloc(sizeof(Node));
	n2->data = 3;
	Node *n3 = (Node*)malloc(sizeof(Node));
	n3->data = 5;
	Node *n4 = (Node*)malloc(sizeof(Node));
	n4->data = 7;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	return n1;
}
int main()
{
	Node* cur = NULL;
	Node* PH1=createList1();
	Node* PH2=createList2();
	Node* Rhead=mergeTwoList(PH1, PH2);
	for (cur = Rhead; cur != NULL; cur = cur->next)
	{
		printf("%d ", cur->data);
	}
	printf("\n");
	system("pause");
	return 0;
}