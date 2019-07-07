#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef struct ListNode
{
	int val;
	struct ListNode *next;
}Node;
Node* createList1()
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 1;
	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->val = 2;
	Node* n3 = (Node*)malloc(sizeof(Node));
	n3->val = 2;
	Node* n4 = (Node*)malloc(sizeof(Node));
	n4->val = 3;
	Node* n5 = (Node*)malloc(sizeof(Node));
	n5->val = 3;
	Node* n6 = (Node*)malloc(sizeof(Node));
	n6->val = 6;
	Node* n7 = (Node*)malloc(sizeof(Node));
	n7->val = 7;
	Node* n8 = (Node*)malloc(sizeof(Node));
	n8->val = 10;
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
Node* createList2()
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 11;
	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->val = 13;
	Node* n3 = (Node*)malloc(sizeof(Node));
	n3->val = 19;
	Node* n4 = (Node*)malloc(sizeof(Node));
	n4->val = 9;
	Node* n5 = (Node*)malloc(sizeof(Node));
	n5->val = 0;
	Node* n6 = (Node*)malloc(sizeof(Node));
	n6->val = 8;
	Node* n7 = (Node*)malloc(sizeof(Node));
	n7->val = 3;
	Node* n8 = (Node*)malloc(sizeof(Node));
	n8->val = 6;
	Node* n9 = (Node*)malloc(sizeof(Node));
	n9->val = 7;
	Node* n10 = (Node*)malloc(sizeof(Node));
	n10->val = 10;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;
	n9->next = n10;
	n10->next = NULL;
	return n1;
}
int GetLength(Node* head)
{
	Node* cur = NULL;
	int length = 0;
	cur = head;
	while (cur != NULL)
	{
		cur = cur->next;
		length++;
	}
	return length;
}
Node* publicNode(Node* head1, Node* head2)
{
	Node* longer = head1;
	Node* shorter = head2;
	int length1 = GetLength(head1);
	int length2 = GetLength(head2);
	int diff = length1 - length2;
	if (length2 > length1)
	{
		longer = head2;
		shorter = head1;
		diff = length2 - length1;
	}
	for (int i = 0; i < diff; i++)
	{
		longer = longer->next;
	}
	while (shorter&&longer != shorter)
	{
		longer = longer->next;
		shorter = shorter->next;
	}
	return longer;
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
	Node* PH1 = createList1();
	Node* PH2 = createList2();
	Node* ret = publicNode(PH1, PH2);
	PrintList(ret);
	system("pause");
	return 0;
}