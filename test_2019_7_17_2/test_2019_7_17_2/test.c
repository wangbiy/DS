#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TreeNode {
	char val;
	struct TreeNode *left;
	struct TreeNode *right;
}Node;
//给定前序和中序构建二叉树
Node* _BuildTree(char* preorder, int preorderSize, int* index, char* inorder, int left, int right)
{
	Node* root = NULL;
	if (*index >= preorderSize)
		return NULL;
	//创建根结点
	root=(Node*)malloc(sizeof(Node));
	if (NULL == root)
		return NULL;
	root->val = preorder[*index];
	root->left = NULL;
	root->right = NULL;
	//确定根节点的左右子树
	int idx = left;
	while (idx<right)
	{
		if (preorder[*index] == inorder[idx])
			break;
		++idx;
	}
	++(*index);
	//左子树范围[left,idx）
	//右子树范围[idx+1,right)
	if (left<idx)
	{
		root->left = _BuildTree(preorder, preorderSize, index, inorder, left, idx);//左子树
	}
	if (idx + 1<right)
	{
		root->right = _BuildTree(preorder, preorderSize, index, inorder, idx + 1, right);//右子树
	}
	return root;
}
Node* buildTree(char* preorder, int preorderSize, char* inorder, int inorderSize){
	int index = 0;
	return _BuildTree(preorder, preorderSize, &index, inorder, 0, inorderSize);

}
int main()
{
	char* preorder = "ABDCEF";
	char* inorder = "DBAECF";
	Node* ret = NULL;
	int preorderSize = strlen(preorder);
	int inorderSize = strlen(inorder);
	ret=buildTree(preorder, preorderSize, inorder, inorderSize);
	system("pause");
}