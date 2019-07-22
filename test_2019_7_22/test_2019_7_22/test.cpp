#include <string.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct BinTreeNode
{
	char val;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}BTNode;
//前序和中序构建二叉树
BTNode* _BuildTree1(char *preorder, char* inorder, int size)
{
	if (size == 0)
		return NULL;
	int rootValue = preorder[0];//根的值
	BTNode* root = NULL;
	root = (BTNode*)malloc(sizeof(BTNode));
	root->val = rootValue;
	int leftsize = -1;//在中序查找rootValue出现的下标，记录在leftsize中
	for (int i = 0; i < size; i++)
	{
		if (inorder[i] == rootValue)
		{
			leftsize = i;
			break;
		}
	}
	root->left = _BuildTree1(preorder + 1, inorder, leftsize);
	root->right = _BuildTree1(preorder + leftsize + 1, inorder + leftsize + 1, size - 1 - leftsize);
	return root;

}
BTNode* BuildTree1(char* preorder, int preorderSize, char* inorder, int inorderSize)
{
	return _BuildTree1(preorder, inorder, inorderSize);
	
}
//中序和后序构建二叉树
BTNode* _BuildTree2(char* inorder, char* postorder, int size)
{
	if (size == 0)
		return NULL;
	int rootValue = postorder[size - 1];
	BTNode* root = NULL;
	root = (BTNode*)malloc(sizeof(BTNode));
	root->val = rootValue;
	int leftsize = -1;
	for (int i = 0; i < size; i++)
	{
		if (inorder[i] == rootValue)
		{
			leftsize = i;
			break;
		}
	}
	root->left = _BuildTree2(inorder, postorder, leftsize);
	root->right = _BuildTree2(inorder + leftsize + 1, postorder + leftsize, size - leftsize - 1);
	return root;
}
BTNode* BuildTree2(char* inorder, int inorderSize, char* postorder, int postorderSize){
	return _BuildTree2(inorder, postorder, inorderSize);
}
int main()
{
	char* preorder = "ABDEHCFG";
	char* inorder = "DBEHAFCG";
	char* postorder = "DAEBFGCA";
	int preorderSize = strlen(preorder);
	int inorderSize = strlen(inorder);
	int postorderSize = strlen(postorder);
	/*BTNode* ret = BuildTree1(preorder, preorderSize, inorder, inorderSize);*/
	BTNode* ret = BuildTree2(inorder, inorderSize, postorder, postorderSize);
	system("pause");
	return 0;
}