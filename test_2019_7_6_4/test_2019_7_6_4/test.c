//��һ������������У������ظ��Ľ�㣬
//��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ��
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
Node* DeleteDupLication1(Node* head)
{
	Node* fackNode=(Node*)malloc(sizeof(Node));//����һ���ٽ�㣬��ΪҪ���ǵ�һ���������ظ���
	fackNode->next = head;
	Node* pre = fackNode;
	Node* p1 = head;
	Node* p2 = head->next;
	if (head == NULL)
		return NULL;
	while (p2 != NULL)//p2���ڿ�ʱ����
	{
		if (p1->val != p2->val)
		{
			pre = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			while (p2 != NULL&&p2->val == p1->val)
			{
				p2 = p2->next;
			}
			//ɾ��p1��p2֮�����еĽڵ�
			pre->next = p2;
			p1 = p2;
			if (p2 != NULL)
			{
				p2 = p2->next;
			}
		}
	}
	return fackNode->next;
}
Node* DeleteDupLication2(Node* head)
{
	Node* pre = NULL;
	Node* p1 = head;
	Node* p2 = head->next;
	if (head == NULL)
		return NULL;
	while (p2 != NULL)//p2���ڿ�ʱ����
	{
		if (p1->val != p2->val)
		{
			pre = p1;
			p1 = p1->next;
			p2 = p2->next;
		}
		else
		{
			while (p2 != NULL&&p2->val == p1->val)
			{
				p2 = p2->next;
			}
			//ɾ��p1��p2֮�����еĽڵ�
			if (pre != NULL)
			{
				pre->next = p2;
				
			}
			else
			{
				head = p2;
			}
			p1 = p2;
			if (p2 != NULL)
			{
				p2 = p2->next;
			}
		}
	}
	return head;
}


int main()
{
	Node* PH = createList();
	/*Node*ret = DeleteDupLication1(PH);*/
	Node*ret = DeleteDupLication2(PH);
	PrintList(ret);
	system("pause");
	return 0;
}