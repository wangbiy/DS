#include "Sort.h"
void print(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void insertSort(int a[], int size)//直接插入排序
{
	for (int i = 1; i < size; ++i)//从第二个元素开始遍历
	{
		int k = a[i];//用k保存遍历的元素
		int end = i - 1;//有序序列的最后一个数据
		//插入
		while (end >= 0 && k < a[end])//k一定在比end小，因此在end前面
		{
			a[end + 1] = a[end];//end向后搬移
			--end;
		}
		a[end + 1] = k;
	}
}
void insertSortWithGap(int a[], int size, int gap)
{

		for (int i = gap; i < size; ++i)//从第二个元素开始遍历
		{
			int k = a[i];//用k保存遍历的元素
			int end = i - gap;//end为当前组的前第gap个数据，因为i要与它的这个分组中的数据进行比较，即与i-gap位置数据比较
			//插入
			while (end >= 0 && k < a[end])//k一定在比end小，因此在end前面
			{
				a[end + gap] = a[end];//end向后gap个位置搬移
				end -= gap;
			}
			a[end + gap] = k;
		}
}
void shellSort(int a[], int size)//希尔排序
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;//可以通过这种方式来计算gap，取素数
		insertSortWithGap(a, size, gap);
		if (gap == 1)
			break;
	}
}
void selectSort1(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int max = 0;//假设第一个数最大
		for (int j = 1; j < size - i; ++j)//找到无序区间最大的数的下标
		{
			if (a[j]>a[max])
				max = j;
		}
		int t = a[max];//最大的与无序区间最后一个数交换
		a[max] = a[size - i - 1];
		a[size - i - 1] = a[max];
	}
}
void selectSort2(int a[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		int min = i;//假设第i个数最小
		for (int j = i+1; j < size ; ++j)//找到无序区间最小的数的下标
		{
			if (a[j]<a[min])
				min = j;
		}
		int t = a[min];//最大的与无序区间第一个数交换
		a[min] = a[i];
		a[i] = a[min];
	}
}
void swap(int* a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
void selectSort3(int a[], int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right)//找最小的放在前面，找最大的放在后面
	{
		int min = left;//假设一开始最大的和最小的都是第一个元素
		int max = left;
		for (int i = left + 1; i <= right; ++i)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i]>a[max])
			{
				max = i;
			}
		}
		swap(&a[min], &a[left]);
		if (max == left)
			max = min;
		swap(&a[max], &a[right]);
		left++;
		right--;
	}
}
void heapify(int a[], int size, int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	if (left >= size)
		return;
	int max = left;
	if (right < size&&a[right]>a[left])
		max = right;
	if (a[index] >= a[max])
	{
		return;
	}
	swap(a + index, a + max);
	heapify(a, size, max);
}
void createHeap(int a[], int size)
{
	for (int i = (size - 1 - 1) / 2; i >= 0; --i)
	{
		heapify(a, size, i);//建大堆
	}
}
void HeapSort(int a[], int size)
{
	createHeap(a, size);
	for (int i = 0; i < size; ++i)
	{
		swap(a, a + size - i - 1);//取堆顶元素与无序区间最后一个元素交换
		heapify(a, size - i-1, 0);//调整堆
	}
}
int partition1(int a[], int left, int right)//hoare方法
{
	int begin = left;
	int end = right;
	int pivot = a[right];//基准值
	while (begin < end)
	{
		while (begin < end&&a[begin] <= pivot)
		{
			begin++;
		}
		while (begin < end&&a[end] >= pivot)
		{
			end--;
		}
		swap(a + begin, a + end);
	}
	swap(a + begin, a + right);
	return begin;
}
int partition2(int a[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = a[right];//基准值
	while (begin < end)
	{
		while (begin < end&&a[begin] <= pivot)
		{
			begin++;
		}
		a[end] = a[begin];
		while (begin < end&&a[end] >= pivot)
		{
			end--;
		}
		a[begin] = a[end];
	
	}
	a[begin] = pivot;
	return begin;
}
int partition3(int a[], int left, int right)
{
	int div = left;
	int i = left;
	for (; i < right; ++i)
	{
		if (a[i] > a[right])
		{
			swap(a + i, a + div);
		}
		else
		{
			div++;
		}
	}
	swap(a + div, a + right);
	return div;
}
void quickSortInternal(int a[], int left, int right)
{
	if (left >= right)
		return;
	//int pivotindex = partition1(a, left, right);//分组
	int pivotindex = partition3(a, left, right);//分组
	quickSortInternal(a, left, pivotindex - 1);
	quickSortInternal(a, pivotindex + 1, right);
}
void quickSort(int a[] , int size)//封装
{
	quickSortInternal(a, 0, size - 1);
}
#include<stack>

void quickSort(int a[], int left, int right)
{
	std::stack<int> s;
	s.push(left);
	s.push(right);
	while (!s.empty())
	{
		int high = s.top();
		s.pop();
		int low = s.top();
		s.pop();
		if (low >= high)
		{
			continue;
		}
		int pivotindex = partition1(a, low, high);
		s.push(pivotindex + 1);
		s.push(high);
		s.push(low);
		s.push(pivotindex - 1);
	}
}
void quickSortNOR(int a[], int size)
{
	quickSort(a, 0, size - 1);
}
void bubbleSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (a[j] >= a[j + 1])
			{
				int t = a[j + 1];
				a[j + 1] = a[j];
				a[j] = t;
			}
		}
	}
}
void MergeData(int a[], int left, int mid, int right, int* tmp)
{
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid;
	int end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while (begin1 < end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 < end2)
	{
		tmp[index++] = a[begin2++];
	}
	memcpy(a + left, tmp + left, (right - left)*sizeof(a[0]));
}
void _MergeSort(int a[], int left, int right,int* tmp)
{
	if (left >= right - 1)
		return;
	int mid = left + ((right - left)>>1);
	_MergeSort(a, left, mid,tmp);
	_MergeSort(a, mid, right,tmp);
	MergeData(a, left, mid, right,tmp); // 归并	
}
void MergeSort(int a[], int size)
{
	int* tmp = (int*)malloc(size*sizeof(a[0]));
	if (NULL == tmp)
		return;
	_MergeSort(a,  0, size - 1,tmp);
	free(tmp);
}



