//输入一个链表，输出该链表中倒数第k个结点。
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct ListNode
{
	int val;
	struct ListNode *next;
}Node;
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
//Node* FindkToTail1(Node* head, unsigned int k)
//{
//	Node* cur = NULL;
//	assert(head);
//	cur = head;
//	int size = 0;
//	while (cur != NULL)
//	{
//		cur = cur->next;
//		size++;
//	}
//	if (size < k)
//		return NULL;
//	else
//	{
//		Node* p = head;
//		for (int i = 0; i < size - k; i++)
//		{
//			p = p->next;
//		}
//		return p;
//	}
//}
Node* FindkToTail2(Node* head, unsigned int k)
{
	assert(head);
	Node* front = head;
	Node* back = head;
	for (int i = 0; i < k; i++)
	{
		if (front == NULL)
			return NULL;
		front = front->next;
	}
	while (front != NULL)
	{
		front = front->next;
		back = back->next;
	}
	return back;
}
int main()
{
	Node* PH=createList();
	//Node* ret = FindkToTail1(PH, 5);
	Node* ret = FindkToTail2(PH, 5);
	PrintList(ret);
	system("pause");
	return 0;
}
