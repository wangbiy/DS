# pragma once
typedef int DLDataType;
typedef struct DListNode//带头双向循环链表
{
	struct DListNode *_pPre;
	struct DListNode *_pNext;
	DLDataType _data;
}DLNode;
void DListInit(DLNode**PHead);
void DListPushBack(DLNode *PHead, DLDataType data);//尾插
void DListPopBack(DLNode *PHead);//尾删
void DListPushFront(DLNode *PHead, DLDataType data);//头插
void DListPopFront(DLNode *PHead);//头删
void DListInsertFront(DLNode *pos, DLDataType data);//任意位置插入
void DListErase(DLNode *pos);//任意位置删除
void PrintDList(DLNode *PHead);//打印
void DListDestroy(DLNode *PHead);//销毁
DLNode* DListFind(DLNode* PHead, DLDataType data);//查找


