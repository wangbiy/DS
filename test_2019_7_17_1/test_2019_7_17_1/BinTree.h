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
BTNode* CreateBinTree(BTDataType* array, int size);//创建二叉树
BTNode* CopyBinTree(BTNode* pRoot);//拷贝二叉树
void DestroyBinTree(BTNode** pRoot);//销毁二叉树
void PreOrder(BTNode* pRoot);//前序遍历递归
void InOrder(BTNode* pRoot); //中序遍历递归
void PostOrder(BTNode* pRoot);//后序遍历递归
void PreOrderNor(BTNode* pRoot);//前序遍历非递归
void InOrderNor(BTNode* pRoot);//中序遍历非递归
void PostOrderNor(BTNode* pRoot);//后序遍历非递归
void LevelOrder(BTNode* pRoot);//层序遍历
int GetNodeCount1(BTNode* pRoot);//获取二叉树中节点的个数1 
int GetNodeCount2(BTNode* pRoot);//获取二叉树中节点的个数方法2 
int Height(BTNode* pRoot);// 求二叉树的高度
int GetLeafNodeCount(BTNode* pRoot);// 获取二叉数中叶子节点的个数 
bool IsBalanceTree(BTNode* pRoot);// 检测二叉树是否平衡O(N^2) 
bool IsBalanceTree_P(BTNode* pRoot, int* height);// 检测二叉树是否平衡O(N) 
int GetKLevelNodeCount(BTNode* pRoot, int K);// 获取二叉树第K层节点的个数
BTNode* find(BTNode* pRoot, char v);//查找值为v的结点，返回节点地址
BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode);// 获取二叉树中某个节点的双亲节点
bool Mirror(BTNode* s, BTNode* t);// 判断二叉树的镜像
void test();
