#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//将两个有序数组合并成一个有序数组
int* merge(int *arr1, int size1, int *arr2, int size2)
{
	int index1 = 0;
	int index2 = 0;
	int index = 0;
	int *tmp = (int*)malloc((sizeof(int))*(size1 + size2));
	while (index1 < size1 && index2 < size2)
	{
		if (arr1[index1] < arr2[index2])
		{
			tmp[index++] = arr1[index1++];
		}
		else
			tmp[index++] = arr2[index2++];
	}
	while (index1 < size1)
	{
		tmp[index++] = arr1[index1++];
	}
	while (index2 < size2)
	{
		tmp[index++] = arr2[index2++];
	}
	return tmp;
}
int main()
{
	int arr1[] = { 1, 2, 3, 4, 6 };
	int arr2[] = { 9, 10, 11, 16, 79 };
	int size1 = sizeof(arr1) / sizeof(int);
	int size2 = sizeof(arr2) / sizeof(int);
	int num = size1 + size2;
	int arr3[10] = { 0 };
	int *ret = merge(arr1, size1, arr2, size2);
	for (int i = 0; i < num; ++i)
	{
		arr3[i] = *ret++;
		printf("%d ", arr3[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}