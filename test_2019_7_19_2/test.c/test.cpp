#include "Sort.h"
int main()
{
	int a[] = { 1, 4, 5, 2, 3, 6, 9, 7, 8 };
	int size = sizeof(a) / sizeof(a[0]);
	printf("ֱ�Ӳ�������:");
	insertSort(a, size);
	print(a, size);
	printf("\n");
	printf("ϣ������:");
	shellSort(a, size);
	print(a, size);
	printf("\n");
	printf("��ѡ������1:");
	selectSort1(a, size);
	print(a, size);
	printf("\n");
	printf("��ѡ������2:");
	selectSort2(a, size);
	print(a, size);
	printf("\n");
	printf("��ѡ������3:");
	selectSort3(a, size);
	print(a, size);
	printf("\n");
	printf("������:");
	HeapSort(a, size);
	print(a, size);
	printf("\n");
	printf("��������:");
	quickSort(a, size);
	print(a, size);
	printf("\n");
	printf("��������ǵݹ�:");
	quickSortNOR(a, size);
	print(a, size);
	printf("\n");
	printf("ð������:");
	bubbleSort(a, size);
	print(a, size);
	printf("\n");
	printf("�鲢����:");
	MergeSort(a, size);
	print(a, size);
	printf("\n");
	system("pause");
	return 0;
}