#include "Slist.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
void SListInit(SList *pl)
{
	assert(pl);
	pl->PHead = NULL;
}
Node* BuySListNode(SDataType data)//������
{
	Node* PNode = (Node*)malloc(sizeof(Node));
	if (PNode == NULL)
	{
		assert(0);
		return NULL;
	}
	PNode->_data = data;
	PNode->_PNext = NULL;
	return PNode;
}
void SListPushBack(SList *pl, SDataType data)
{
	Node *PNewNode = NULL;
	assert(pl);
	Node *Pcur = NULL;
	PNewNode = BuySListNode(data);
	Pcur = pl->PHead;//��ͷ��ʼ
	if (pl->PHead == NULL)//���ͷ���Ϊ�գ�ֱ�ӷ����½��
	{
		pl->PHead = PNewNode;
	}
	else
	{
		while (Pcur->_PNext)//ֻҪһֱ������һ���ڵ㣬���������
		{
			Pcur = Pcur->_PNext;
		}
		Pcur->_PNext = PNewNode;
	}
}
void SListPopBack(SList *pl)
{
	assert(pl);
	if (pl->PHead == NULL)//û�нڵ�
	{
		return;
	}
	else if (NULL == pl->PHead->_PNext)//ֻ��һ���ڵ�
	{
		free(pl->PHead);
		pl->PHead = NULL;
	}
	else
	{
		Node *PTailNode = pl->PHead;//β���
		Node *PPreTail = NULL;//ǰһ�����
		while (PTailNode->_PNext)
		{
			PPreTail = PTailNode;
			PTailNode = PTailNode->_PNext;
		}
		free(PTailNode);
		PPreTail->_PNext = NULL;
	}
}
void SListPushFront(SList *pl, SDataType data)//ͷ��
{
	Node *PNewNode = NULL;
	assert(pl);
	PNewNode = BuySListNode(data);
	PNewNode->_PNext = pl->PHead;
	pl->PHead = PNewNode;
}
void SListPopFront(SList *pl)//ͷɾ
{
	assert(pl);
	if (pl->PHead == NULL)
		return;
	else
	{
		Node *PDelNode = pl->PHead;
		pl->PHead = PDelNode->_PNext;
		free(PDelNode);
	}
}
void SListInsertAfter(Node *pos,SDataType data)//����λ�ò���
{
	Node *PNewNode = NULL;
	if (NULL == pos)
		return;
	PNewNode = BuySListNode(data);//�����½��
	PNewNode->_PNext = pos->_PNext;
	pos->_PNext = PNewNode;
}
void SListErase(SList *pl, Node *pos)//����λ��ɾ��
{
	Node *PPrePos = NULL;
	assert(pl);
	if (pl->PHead == NULL || pos == NULL)
	{
		return;
	}
	if (pos == pl->PHead)//pos�պ��ڵ�һ���ڵ��λ��
	{
		pl->PHead = pos->_PNext;
		free(pos);
		return;
	}
	PPrePos = pl->PHead;
	while (PPrePos->_PNext != pos)
	{
		PPrePos = PPrePos->_PNext;
	}
	PPrePos->_PNext = pos->_PNext;
	free(pos);
}
Node* SListFind(SList *pl, SDataType data)
{
	Node *Pcur = pl->PHead;
	assert(pl);
	while (Pcur)
	{
		if (Pcur->_data == data)
		{
			return Pcur;
		}
		else Pcur = Pcur->_PNext;
	}
	return  Pcur;
}
int SListSize(SList *pl)
{
	Node *Pcur = NULL;
	int count = 0;
	assert(pl);
	Pcur = pl->PHead;
	while (Pcur)
	{
		count++;
		Pcur = Pcur->_PNext;
	}
	return count;
}
Node* SListFront(SList *pl)
{
	assert(pl);
	return pl->PHead;
}
Node* SListBack(SList *pl)//���뱣֤��β��㣬��ȡ���һ���ڵ�
{
	Node *Pcur = NULL;
	assert(pl);
	Pcur = pl->PHead;
	while (Pcur->_PNext)
	{
		Pcur = Pcur->_PNext;
	}
	return Pcur;
}
void PrintSList(SList *pl)
{
	Node *Pcur = NULL;
	assert(pl);
	Pcur = pl->PHead;
	while (Pcur)
	{
		printf("%d------>", Pcur->_data);
		Pcur = Pcur->_PNext;
	}
	printf("NULL\n");
}
void SListDestroy(SList *pl)
{
	Node *Pcur = NULL;
	assert(pl);
	Pcur = pl->PHead;
	while (Pcur)
	{
		pl->PHead = Pcur->_PNext;
		free(Pcur);
		Pcur = pl->PHead;
	}
	pl->PHead = NULL;
}
int SListEmpty(SList *pl)
{
	assert(pl);
	return NULL == pl->PHead;
}
void SListPushFront2(Node *NodeHead, SDataType data)//��ͷ�ڵ��ͷ��
{
	assert(NodeHead);
	Node *PNewNode = BuySListNode(data);
	PNewNode->_PNext = NodeHead->_PNext;
	NodeHead->_PNext = PNewNode;
}
void SListPushBack2(Node**PHead, SDataType data)//��������ṹ��β�壬����ͷ���
{
	assert(PHead);
	Node *PNewNode = BuySListNode(data);
	if (NULL == *PHead)
	{
		*PHead = PNewNode;
	}
	else
	{
		Node *cur = NULL;
		cur=*PHead;
		while (cur->_PNext)
		{
			cur = cur->_PNext;
		}
		cur->_PNext = PNewNode;
	}
}