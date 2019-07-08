//给定一个链表，每个节点包含一个额外增加的随机指针，
//该指针可以指向链表中的任何结点或空节点，要求返回这个链表的深度拷贝
#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
	int val;
	struct ListNode* next;
	struct ListNode* random;
}Node;
Node* copyrandomList(Node* head)
{
	Node* cur = head;
	if (head == NULL)
		return NULL;
	while (cur != NULL)
	{
		//先复制一份值，将第二个链表相同的值放在原链表相同的值的后面，连成一个链表
		//成为1 1 2 2 3 3 4 4 NULL
		Node* node = (Node*)malloc(sizeof(Node));
		node->val = cur->val;
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	cur = head;
	while (cur != NULL)
	{
		if (cur->random == NULL)
		{
			cur->next->random = NULL;
		}
		else
		{
			cur->next->random = cur->random->next;
		}
		//然后拆开两个链表
		cur = cur->next->next;//一次跳两个
	}
	cur = head;
	Node* NewNode = head->next;
	while (cur != NULL)
	{
		Node* node = cur->next;
		cur->next = node->next;
		if (node->next != NULL)
		{
			node->next = node->next->next;
		}
		cur = cur->next;
	}
	return NewNode;
}
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
	n1->next = n2;
	n1->random = n2;
	n2->next = n3;
	n2->random = n1;
	n3->next = n4;
	n3->random = n3;
	n4->next = NULL;
	n4->random = NULL;
	return n1;
}
int main()
{
	Node* PH = createList();
	Node* ret = copyrandomList(PH);
	system("pause");
	return 0;
}