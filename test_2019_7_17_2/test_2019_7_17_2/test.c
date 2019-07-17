#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TreeNode {
	char val;
	struct TreeNode *left;
	struct TreeNode *right;
}Node;
//����ǰ������򹹽�������
Node* _BuildTree(char* preorder, int preorderSize, int* index, char* inorder, int left, int right)
{
	Node* root = NULL;
	if (*index >= preorderSize)
		return NULL;
	//���������
	root=(Node*)malloc(sizeof(Node));
	if (NULL == root)
		return NULL;
	root->val = preorder[*index];
	root->left = NULL;
	root->right = NULL;
	//ȷ�����ڵ����������
	int idx = left;
	while (idx<right)
	{
		if (preorder[*index] == inorder[idx])
			break;
		++idx;
	}
	++(*index);
	//��������Χ[left,idx��
	//��������Χ[idx+1,right)
	if (left<idx)
	{
		root->left = _BuildTree(preorder, preorderSize, index, inorder, left, idx);//������
	}
	if (idx + 1<right)
	{
		root->right = _BuildTree(preorder, preorderSize, index, inorder, idx + 1, right);//������
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