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
void DListInit(DLNode**PHead)//初始化,因为改变了指针
{
	assert(PHead);
	*PHead = BuyDListNode(0);
	(*PHead)->_pNext = *PHead;
	(*PHead)->_pPre = *PHead;
}
void DListPushBack(DLNode *PHead, DLDataType data)//尾插
{
	DLNode* pNewNode = NULL;
	assert(PHead);
	pNewNode = BuyDListNode(data);
	//不破坏链表的结构，将新节点链接到链表上去
	pNewNode->_pPre = PHead->_pPre;
	pNewNode->_pNext = PHead;
	//破坏链表结构
	PHead->_pPre->_pNext = pNewNode;
	PHead->_pPre = pNewNode;
}
void DListPopBack(DLNode *PHead)//尾删
{
	assert(PHead);
}
void PrintDList(DLNode *PHead)//打印
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


