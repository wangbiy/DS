#pragma once
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Heap
{
	int a[100];
	int size;
}Heap;
void HeapInit(Heap* heap, int a[], int size);//�ѵĳ�ʼ��
void HeapPush(Heap* heap, int val);//���뵽β��
void HeapPop(Heap* heap);//ɾ��
int HeapTop(Heap* heap);//���ضѶ�Ԫ��