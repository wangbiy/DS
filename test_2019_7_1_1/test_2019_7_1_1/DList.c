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
	return pNewNode;
}
void DListInit(DLNode**PHead)//��ʼ��
{
	assert(PHead);
	*PHead = BuyDListNode(0);
	(*PHead)->_pNext = *PHead;
	(*PHead)->_pPre = *PHead;
}
void DListPushBack(DLNode *PHead, DLDataType data)//β��
{
	DLNode * pNewNode = NULL;
	assert(PHead);
	pNewNode = BuyDListNode(data);
	//���ƻ�����Ľṹ�����½ڵ����ӵ�������ȥ
	pNewNode->_pNext = PHead;
	pNewNode->_pPre = PHead->_pPre;
	//�ƻ�����ṹ
	PHead->_pPre->_pNext = pNewNode;
	PHead->_pPre = pNewNode;
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


