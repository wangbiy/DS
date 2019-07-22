#pragma once
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef char BTDataType;
typedef struct BTNode
{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;
BTNode* CreateBinTree(BTDataType* array, int size);//����������
BTNode* CopyBinTree(BTNode* pRoot);//����������
void DestroyBinTree(BTNode** pRoot);//���ٶ�����
void PreOrder(BTNode* pRoot);//ǰ������ݹ�
void InOrder(BTNode* pRoot); //��������ݹ�
void PostOrder(BTNode* pRoot);//��������ݹ�
void PreOrderNor(BTNode* pRoot);//ǰ������ǵݹ�
void InOrderNor(BTNode* pRoot);//��������ǵݹ�
void PostOrderNor(BTNode* pRoot);//��������ǵݹ�
void LevelOrder(BTNode* pRoot);//�������
int GetNodeCount1(BTNode* pRoot);//��ȡ�������нڵ�ĸ���1 
int GetNodeCount2(BTNode* pRoot);//��ȡ�������нڵ�ĸ�������2 
int Height(BTNode* pRoot);// ��������ĸ߶�
int GetLeafNodeCount(BTNode* pRoot);// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
bool IsBalanceTree(BTNode* pRoot);// ���������Ƿ�ƽ��O(N^2) 
bool IsBalanceTree_P(BTNode* pRoot, int* height);// ���������Ƿ�ƽ��O(N) 
int GetKLevelNodeCount(BTNode* pRoot, int K);// ��ȡ��������K��ڵ�ĸ���
BTNode* find(BTNode* pRoot, char v);//����ֵΪv�Ľ�㣬���ؽڵ��ַ
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);// ��ȡ��������ĳ���ڵ��˫�׽ڵ�
bool Mirror(BTNode* s, BTNode* t);// �ж϶������ľ���
void test();
