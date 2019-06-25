
typedef int DataType;
typedef struct SeqList
{
	DataType *arr;
	int size;//有效元素个数
	int Capacity;//容量
}SeqList,*PSeqList;
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