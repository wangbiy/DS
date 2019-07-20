#include "heap.h"
void heapify1(int a[], int size, int index)//向下调整将它调整为小堆，前提是左右子树必须是堆
{
	int left = 2 * index + 1;//左孩子
	int right = 2 * index + 2;//右孩子
	if (left >= size)
		return;
	int min = left;
	if (right < size&&a[left] > a[right])//右孩子存在并且比较左孩子与右孩子
	{
		min = right;//右孩子比较小
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
void heapify2(int a[], int size, int index)//调整为大堆
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
void createHeap1(int a[], int size)//建小堆
{
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		heapify1(a, size, i);
	}
}
void createHeap2(int a[], int size)//建大堆
{
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		heapify2(a, size, i);
	}
}
void HeapInit(Heap* heap, int a[], int size)//堆的初始化
{
	heap->a = (int*)malloc(sizeof(int)*size);
	heap->size = size;
	heap->capacity = size;
	for (int i = 0; i < size; ++i)
	{
		heap->a[i] = a[i];
	}
	createHeap1(heap->a, heap->size);//建小堆
}
void AdjustUp(int a[], int index)//要实现堆的插入，将元素插入数组的尾上，向上调整
{
	while (index>0)
	{
		if (index == 0)
			return;
		int parent = (index - 1) / 2;//计算index的双亲节点
		if (a[parent] <= a[index])//调整为小堆
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
void checkCapacity(Heap* heap)
{
	if (heap->size == heap->capacity)
	{
		int newCapacity = 2 * (heap->capacity);
		int* tmp = (int*)malloc(sizeof(int)*newCapacity);
		memcpy(tmp, heap->a, sizeof(int)*(heap->size));
		free(heap->a);
		heap->a = tmp;
		heap->capacity = newCapacity;
	}
}
void HeapPush(Heap* heap, int val)//插入到尾上
{
	checkCapacity(heap);
	heap->a[heap->size++] = val;
	AdjustUp(heap->a, heap->size - 1);
}
void HeapPop(Heap* heap)//删除
{
	assert(heap);
	heap->a[0] = heap->a[heap->size - 1];//将根与最后一个结点交换
	heap->size--;//删除最后一个数据
	heapify1(heap->a, heap->size, 0);//向下调整
}
int HeapTop(Heap* heap)//返回堆顶元素
{
	assert(heap);
	return heap->a[0];
}
int HeapSize(Heap* heap)
{
	return heap->size;
}
int HeapEmpty(Heap* heap)
{
	return 0 == heap->size;
}
void HeapDestroy(Heap* heap)
{
	if (heap->a)
	{
		free(heap->a);
		heap->capacity = 0;
		heap->size = 0;
	}
}