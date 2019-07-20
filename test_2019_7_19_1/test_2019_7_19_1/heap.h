#pragma once
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Heap
{
	int *a;
	int size;
	int capacity;
}Heap;
void HeapInit(Heap* heap, int a[], int size);//堆的初始化
void HeapPush(Heap* heap, int val);//插入到尾上
void HeapPop(Heap* heap);//删除
int HeapTop(Heap* heap);//返回堆顶元素
int HeapSize(Heap* heap);//返回有效元素个数
int HeapEmpty(Heap* heap);
void HeapDestroy(Heap* heap);//销毁