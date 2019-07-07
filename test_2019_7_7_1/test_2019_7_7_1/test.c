//判断链表是否为回文结构
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
	n1->val = 1;
	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->val = 2;
	Node* n3 = (Node*)malloc(sizeof(Node));
	n3->val = 3;
	Node* n4 = (Node*)malloc(sizeof(Node));
	n4->val = 4;
	Node* n5 = (Node*)malloc(sizeof(Node));
	n5->val = 4;
	Node* n6 = (Node*)malloc(sizeof(Node));
	n6->val = 3;
	Node* n7 = (Node*)malloc(sizeof(Node));
	n7->val = 2;
	Node* n8 = (Node*)malloc(sizeof(Node));
	n8->val = 1;
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
Node* FindMiddle(Node* head)
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
Node* reverseSList(Node* head)
{
	Node*cur = head;
	Node* result = NULL;
	while (cur != NULL)
	{
		Node* next = cur->next;
		cur->next = result;
		result = cur;
		cur = next;
	}
	return result;
}
void checkHuiwen(Node* head)
{
	Node* middle = FindMiddle(head);
	Node* result = reverseSList(middle);
	Node* c1 = head;
	Node* c2 = result;
	while (c1 != NULL&&c2 != NULL)
	{
		if (c1->val != c2->val)
		{
			printf("不是回文结构!\n");
		}
		c1 = c1->next;
		c2 = c2->next;
	}
	printf("是回文结构!\n");
}
int main()
{
	Node* PH = createList();
	checkHuiwen(PH);
	system("pause");
	return 0;
}
