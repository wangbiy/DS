#include "SeqList.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <memory.h>
#include <stdlib.h>
void SeqListInit(PSeqList ps)
{
	assert(ps);
	ps->arr = (DataType*)malloc(sizeof(DataType)* 10);
	if (NULL == ps->arr)
	{
		assert(0);
		return;
	}
	ps->Capacity = 10;
	ps->size = 0;
}
void SeqListDestroy(PSeqList ps)
{
	assert(ps);
	if (ps->arr)
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->Capacity = 0;
		ps->size = 0;
	}
}
void CheckCapacity(PSeqList ps)//检测容量
{
	assert(ps);
	if (ps->size == ps->Capacity)
	{
		int newCapacity = ps->Capacity * 2;
		DataType *pTmp = (DataType*)malloc(sizeof(DataType)*newCapacity);
		if (NULL == pTmp)
		{
			assert(0);
			return;
		}
		memcpy(pTmp, ps->arr, ps->size*sizeof(DataType));
		free(ps->arr);
		ps->arr = pTmp;
		ps->Capacity = newCapacity;
	}
}
void SeqListPushBack(PSeqList ps, DataType data)//尾插
{
	assert(ps);
	//判断是否增容
	CheckCapacity(ps);
	ps->size = data;
	ps->size++;
}
void SeqListPopBack(PSeqList ps)//尾删
{
	assert(ps);
	ps->size--;
}
void SeqListPushFront(PSeqList ps, DataType data)//头插
{
	assert(ps);
	//判断是否增容
	CheckCapacity(ps);
	for (int i = ps->size - 1; i >= 0; --i)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[0] = data;
	ps->size++;
}
void SeqListPopFront(PSeqList ps)//头删
{
	assert(ps);
	for (int i = 0; i < ps->size - 1; ++i)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
void SeqListInsert(PSeqList ps, int pos, DataType data)//任意位置插入
{
	assert(ps);
	if (pos<0 || pos>ps->size)
	{
		printf("插入位置不合法!\n");
		return;
	}
	//检测是否增容
	CheckCapacity(ps);
	for (int i = ps->size - 1; i >= pos; --i)
	{
		ps->arr[i + 1] = ps->arr[i];
	}
	ps->arr[pos] = data;
	ps->size++;
}
void SeqListErase(PSeqList ps, int pos)//任意位置删除
{
	assert(ps);
	if (pos < 0 || pos >= ps->size)
	{
		printf("删除位置不合法!\n");
		return;
	}
	for (int i = pos; i < ps->size; ++i)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
int SeqListFind(PSeqList ps, DataType data)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		if (ps->arr[i] == data)
			return i;
	}
	return -1;
}

void PrintSeqList(PSeqList ps)
{
	assert(ps);
	for (int i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}
