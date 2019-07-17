#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//�������Ĳ���
typedef struct BinTreeNode
{
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	char val;
}BTNode;
BTNode* createBinTree(char* arr, int size);//����������
void DestroyBinTree(BTNode** root);//�����������
void PreOrderTraversal(BTNode* root);//�ݹ��������
void inOrderTraversal(BTNode* root);//�ݹ��������
void postOrderTraversal(BTNode* root);//�ݹ�������
int GetHeight(BTNode* root);//��߶�
int getNodeCount1(BTNode* root);//��ڵ������һ�ַ���
int getNodeCount2(BTNode* root);//��ڵ�����ڶ��ַ���
int GetLeafCount(BTNode* root);//��Ҷ�ӽڵ����
int getKlevelCount(BTNode* root, int k);//���k���ϵĽ�����
BTNode* find(BTNode* root, char v);//����ֵΪv�Ľ�㣬���ؽڵ��ַ
#include <queue>
void levelOrderTraversal(BTNode* root);//�������
bool isCompleteTree(BTNode* root);//�ж���ȫ������
BTNode* copyBinTree(BTNode* root);//����������
