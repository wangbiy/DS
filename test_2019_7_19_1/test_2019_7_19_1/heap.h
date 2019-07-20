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
void HeapInit(Heap* heap, int a[], int size);//�ѵĳ�ʼ��
void HeapPush(Heap* heap, int val);//���뵽β��
void HeapPop(Heap* heap);//ɾ��
int HeapTop(Heap* heap);//���ضѶ�Ԫ��
int HeapSize(Heap* heap);//������ЧԪ�ظ���
int HeapEmpty(Heap* heap);
void HeapDestroy(Heap* heap);//����