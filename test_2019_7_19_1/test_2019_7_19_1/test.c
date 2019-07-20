#include "heap.h"
void test()
{
	int a[] = { 1, 5, 3, 8, 7, 6 };
	int size = sizeof(a) / sizeof(int);
	Heap heap;
	HeapInit(&heap, a, size);//建小堆,及堆的初始化
	HeapPush(&heap, 9);//插入9到堆上
	HeapPop(&heap);//删除堆顶元素
	int ret=HeapTop(&heap);//返回堆顶元素
	int count = HeapSize(&heap);
	HeapDestroy(&heap);
}
int main()
{
	test();
	system("pause");
	return 0;
}