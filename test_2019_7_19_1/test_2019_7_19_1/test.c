#include "heap.h"
void test()
{
	int a[] = { 1, 5, 3, 8, 7, 6 };
	int size = sizeof(a) / sizeof(int);
	Heap heap;
	HeapInit(&heap, a, size);//��С��,���ѵĳ�ʼ��
	HeapPush(&heap, 9);//����9������
	HeapPop(&heap);//ɾ���Ѷ�Ԫ��
	int ret=HeapTop(&heap);//���ضѶ�Ԫ��
	int count = HeapSize(&heap);
	HeapDestroy(&heap);
}
int main()
{
	test();
	system("pause");
	return 0;
}