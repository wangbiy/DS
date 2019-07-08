//给定一个链表，返回链表开始入环的第一个节点，如果链表无环，则返回NULL
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
	int val;
	struct ListNode* next;
}Node;
Node* hascycle(Node* head)
{
	//判断是否有环,利用快慢指针找相遇点
	Node* fast = head;
	Node* slow = head;
	if (head == NULL)
		return NULL;
	do
	{
		fast = fast->next;
		if (fast == NULL)
			return NULL;
		fast = fast->next;
		if (fast == NULL)
			return NULL;
		slow = slow->next;
	} while (fast != slow);//fast或者slow都为相遇点
	//找环的入口点
	//一个指针从起点出发，一个指针从相遇点出发，各自走一步，一定会相遇在环的入口点
	Node* p1 = head;
	Node* p2 = slow;
	while (p1 != p2)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}
Node* createList()
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 1;
	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->val = 2;
	Node* n3 = (Node*)malloc(sizeof(Node));
	n3->val = 0;
	Node* n4 = (Node*)malloc(sizeof(Node));
	n4->val = 3;
	Node* n5 = (Node*)malloc(sizeof(Node));
	n5->val = 5;
	Node* n6 = (Node*)malloc(sizeof(Node));
	n6->val = 8;
	Node* n7 = (Node*)malloc(sizeof(Node));
	n7->val = 4;
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
	n10->next = n5;
	return n1;
}
int main()
{
	Node* PH = createList();
	Node* ret = hascycle(PH);
	system("pause");
	return 0;
}