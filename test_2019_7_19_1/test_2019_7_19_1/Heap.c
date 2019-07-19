#include "heap.h"
void heapify1(int a[], int size, int index)//���µ�����������ΪС�ѣ�ǰ�����������������Ƕ�
{
	int left = 2 * index + 1;//����
	int right = 2 * index + 2;//�Һ���
	if (left >= size)
		return;
	int min = left;
	if (right < size&&a[left] > a[right])//�Һ��Ӵ��ڲ��ұȽ��������Һ���
	{
		min = right;//�Һ��ӱȽ�С
	}
	if (a[index] <= a[min])
		return;
	else
	{
		int t = a[min];
		a[min] = a[index];
		a[index] = t;
	}
	heapify1(a, size, min);
}
void heapify2(int a[], int size, int index)//����Ϊ���
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left >= size)
		return;
	int max = left;
	if (right<size&&a[right]>a[left])
	{
		max = right;
	}
	if (a[index] >= a[max])
		return;
	else
	{
		int t = a[max];
		a[max] = a[index];
		a[index] = t;
	}
	heapify2(a, size, max);
}
void createHeap1(int a[], int size)//��С��
{
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		heapify1(a, size, i);
	}
}
void createHeap2(int a[], int size)//�����
{
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		heapify2(a, size, i);
	}
}
void HeapInit(Heap* heap, int a[], int size)//�ѵĳ�ʼ��
{
	for (int i = 0; i < size; ++i)
	{
		heap->a[i] = a[i];
	}
	heap->size = size;
	createHeap1(heap->a, heap->size);//��С��
}
void AdjustUp(int a[], int index)//Ҫʵ�ֶѵĲ��룬��Ԫ�ز��������β�ϣ����ϵ���
{
	while (index>0)
	{
		if (index == 0)
			return;
		int parent = (index - 1) / 2;//����index��˫�׽ڵ�
		if (a[parent] <= a[index])//����ΪС��
			return;
		else
		{
			int t = a[index];
			a[index] = a[parent];
			a[parent] = t;
		}
		index = parent;
	}
}
void HeapPush(Heap* heap, int val)//���뵽β��
{
	heap->a[heap->size++] = val;
	AdjustUp(heap->a, heap->size - 1);
}
void HeapPop(Heap* heap)//ɾ��
{
	assert(heap->size>0);
	heap->a[0] = heap->a[heap->size - 1];//���������һ����㽻��
	heap->size--;//ɾ�����һ������
	heapify1(heap->a, heap->size, 0);//���µ���
}
int HeapTop(Heap* heap)//���ضѶ�Ԫ��
{
	assert(heap->size>0);
	return heap->a[0];
}