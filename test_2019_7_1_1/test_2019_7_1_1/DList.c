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
	assert(PHead);//链表是否存在,PHead代表头结点,只要链表不销毁，这个头结点永远存在
	DLNode* pDelNode;
	//链表为空
	if (PHead == PHead->_pNext)
		return;
	//链表只有一个节点和有两个以上节点
	pDelNode = PHead->_pPre;
	pDelNode->_pPre->_pNext = PHead;
	PHead->_pPre = pDelNode->_pPre;
	free(pDelNode);
}
void DListPushFront(DLNode *PHead, DLDataType data)//头插
{
	DLNode *pNewNode = NULL;
	assert(PHead);
	pNewNode = BuyDListNode(data);
	//先链接上去，不改变链表结构
	pNewNode->_pNext = PHead->_pNext;
	pNewNode->_pPre = PHead;
	//改变链表结构
	PHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;
}
void DListPopFront(DLNode *PHead)//头删
{
	DLNode* pDelNode = NULL;
	assert(PHead);
	if (PHead->_pNext == PHead)//为空
		return;
	pDelNode = PHead->_pNext;
	PHead->_pNext = pDelNode->_pNext;
	pDelNode->_pNext->_pPre = PHead;
	free(pDelNode);
}
DLNode* DListFind(DLNode* PHead, DLDataType data)//查找
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
void DListInsertFront(DLNode *pos, DLDataType data)//任意位置插入
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
void DListErase(DLNode *pos)//任意位置删除
{
	if (NULL == pos)
		return;
	pos->_pPre->_pNext = pos->_pNext;
	pos->_pNext->_pPre = pos->_pPre;
	free(pos);	
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
//将链表中所有的有效结点清理掉
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
void DListDestroy(DLNode**PHead)//销毁
{
	assert(PHead);
	DListClear(*PHead);
	free(*PHead);
	*PHead = NULL;
}



