#pragma once
typedef int DataType;
typedef struct SeqList
{
	DataType *arr;
	int size;//有效元素个数
	int Capacity;//容量
}SeqList, *PSeqList;
void SeqListInit(PSeqList ps);
void SeqListDestroy(PSeqList ps);
void SeqListPushBack(PSeqList ps, DataType data);
void SeqListPopBack(PSeqList ps);
void PrintSeqList(PSeqList ps);
void SeqListPushFront(PSeqList ps, DataType data);
void SeqListPopFront(PSeqList ps);
void SeqListInsert(PSeqList ps, int pos, DataType data);
void SeqListErase(PSeqList ps, int pos);
int SeqListFind(PSeqList ps, DataType data);
int SeqListCapacity(PSeqList ps);
int SeqListSize(PSeqList ps);
int SeqListEmpty(PSeqList ps);
DataType SeqListFront(PSeqList ps);
DataType SeqlistBack(PSeqList ps);
void SeqListRemove(PSeqList ps, DataType data);
void SeqListRemoveAll(PSeqList ps, DataType data);