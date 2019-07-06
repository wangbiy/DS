//给定一个带有头结点 head 的非空单链表，
//返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点。
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef struct ListNode
{
	int val;
	struct ListNode *next;
}Node;
//Node* MiddleNode1(Node *head)
//{
//	assert(head);
//	Node* cur = head;
//	int size = 0;
//	while (cur != NULL)
//	{
//		cur = cur->next;
//		size++;
//	}
//	Node* p = head;
//	for (int i = 0; i < size / 2; i++)
//	{
//		p = p->next;
//	}
//	return p;
//}
Node* MiddleNode2(Node *head)
{
	Node* fast = head;
	Node* slow = head;
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast == NULL)
			break;
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
Node* createList()
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 1;
	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->val = 5;
	Node* n3 = (Node*)malloc(sizeof(Node));
	n3->val = 2;
	Node* n4 = (Node*)malloc(sizeof(Node));
	n4->val = 4;
	Node* n5 = (Node*)malloc(sizeof(Node));
	n5->val = 3;
	Node* n6 = (Node*)malloc(sizeof(Node));
	n6->val = 6;
	Node* n7 = (Node*)malloc(sizeof(Node));
	n7->val = 0;
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
	assert(head);
	Node* cur = NULL;
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
	//Node* ret = MiddleNode1(PH);
	Node* ret = MiddleNode2(PH);
	PrintList(ret);
	system("pause");
	return 0;
}