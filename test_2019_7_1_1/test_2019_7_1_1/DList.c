#include "DList.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
DLNode* BuyDListNode(DLDataType data)
{
	DLNode* pNewNode = (DLNode*)malloc(sizeof(DLNode));
	if (NULL == pNewNode)
	{
		assert(0);
		return NULL;
	}
	pNewNode->_pNext = NULL;
	pNewNode->_pPre = NULL;
	pNewNode->_data = data;
	return pNewNode;
}
void DListInit(DLNode**PHead)//��ʼ��,��Ϊ�ı���ָ��
{
	assert(PHead);
	*PHead = BuyDListNode(0);
	(*PHead)->_pNext = *PHead;
	(*PHead)->_pPre = *PHead;
}
void DListPushBack(DLNode *PHead, DLDataType data)//β��
{
	DLNode* pNewNode = NULL;
	assert(PHead);
	pNewNode = BuyDListNode(data);
	//���ƻ�����Ľṹ�����½ڵ����ӵ�������ȥ
	pNewNode->_pPre = PHead->_pPre;
	pNewNode->_pNext = PHead;
	//�ƻ�����ṹ
	PHead->_pPre->_pNext = pNewNode;
	PHead->_pPre = pNewNode;
}
void DListPopBack(DLNode *PHead)//βɾ
{
	assert(PHead);//�����Ƿ����,PHead����ͷ���,ֻҪ�������٣����ͷ�����Զ����
	DLNode* pDelNode;
	//����Ϊ��
	if (PHead == PHead->_pNext)
		return;
	//����ֻ��һ���ڵ�����������Ͻڵ�
	pDelNode = PHead->_pPre;
	pDelNode->_pPre->_pNext = PHead;
	PHead->_pPre = pDelNode->_pPre;
	free(pDelNode);
}
void DListPushFront(DLNode *PHead, DLDataType data)//ͷ��
{
	DLNode *pNewNode = NULL;
	assert(PHead);
	pNewNode = BuyDListNode(data);
	//��������ȥ�����ı�����ṹ
	pNewNode->_pNext = PHead->_pNext;
	pNewNode->_pPre = PHead;
	//�ı�����ṹ
	PHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;
}
void DListPopFront(DLNode *PHead)//ͷɾ
{
	DLNode* pDelNode = NULL;
	assert(PHead);
	if (PHead->_pNext == PHead)//Ϊ��
		return;
	pDelNode = PHead->_pNext;
	PHead->_pNext = pDelNode->_pNext;
	pDelNode->_pNext->_pPre = PHead;
	free(pDelNode);
}
DLNode* DListFind(DLNode* PHead, DLDataType data)//����
{
	DLNode* pCur = NULL;
	assert(PHead);
	pCur = PHead->_pNext;
	while (pCur != PHead)
	{
		if (pCur->_data == data)
			return pCur;
		pCur = pCur->_pNext;
	}
	return NULL;
}
void DListInsertFront(DLNode *pos, DLDataType data)//����λ�ò���
{
	DLNode* pNewNode = NULL;
	if (pos == NULL)
		return;
	pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	pos->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;
}
void DListErase(DLNode *pos)//����λ��ɾ��
{
	if (NULL == pos)
		return;
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	free(pos);	
}
void PrintDList(DLNode *PHead)//��ӡ
{
	DLNode * pCur = NULL;
	assert(PHead);
	pCur = PHead->_pNext;
	while (pCur!=PHead)
	{
		printf("%d ", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("\n");
}
//�����������е���Ч��������
void DListClear(DLNode *PHead)
{
	DLNode *pCur = NULL;
	assert(PHead);
	pCur = PHead->_pNext;
	while (pCur != PHead)
	{
		PHead->_pNext = pCur->_pNext;
		free(pCur);
		pCur = PHead->_pNext;
	}
	PHead->_pNext = PHead;
	PHead->_pPre = PHead;
}
void DListDestroy(DLNode**PHead)//����
{
	assert(PHead);
	DListClear(*PHead);
	free(*PHead);
	*PHead = NULL;
}



