#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
void print(int a[], int size);
void insertSort(int a[], int size);//直接插入排序
void shellSort(int a[], int size);//希尔排序
void selectSort1(int a[], int size);//简单选择排序1
void selectSort2(int a[], int size);//简单选择排序2
void selectSort3(int a[], int size);//简单选择排序3
void HeapSort(int a[], int size);//堆排序
void quickSort(int a[], int size);//快速排序
void quickSortNOR(int a[], int size);//快速排序非递归
void MergeSort(int a[], int size);//归并排序
void bubbleSort(int a[], int size);//冒泡排序
void countSort(int a[], int size);//计数排序

