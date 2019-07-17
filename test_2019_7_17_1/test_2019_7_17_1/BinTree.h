#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//二叉树的操作
typedef struct BinTreeNode
{
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	char val;
}BTNode;
BTNode* createBinTree(char* arr, int size);//创建二叉树
void DestroyBinTree(BTNode** root);//后序遍历销毁
void PreOrderTraversal(BTNode* root);//递归先序遍历
void inOrderTraversal(BTNode* root);//递归中序遍历
void postOrderTraversal(BTNode* root);//递归后序遍历
int GetHeight(BTNode* root);//求高度
int getNodeCount1(BTNode* root);//求节点个数第一种方法
int getNodeCount2(BTNode* root);//求节点个数第二种方法
int GetLeafCount(BTNode* root);//求叶子节点个数
int getKlevelCount(BTNode* root, int k);//求第k层上的结点个数
BTNode* find(BTNode* root, char v);//查找值为v的结点，返回节点地址
#include <queue>
void levelOrderTraversal(BTNode* root);//层序遍历
bool isCompleteTree(BTNode* root);//判断完全二叉树
BTNode* copyBinTree(BTNode* root);//拷贝二叉树
