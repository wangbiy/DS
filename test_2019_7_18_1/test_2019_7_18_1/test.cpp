#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
}Node;
////找最近公共祖先
//bool exists(Node* root, Node* t)
//{
//	if (root == NULL)
//		return false;
//	if (root == t)
//		return true;
//	if (exists(root->left, t))
//		return true;
//	return exists(root->right, t);	
//}
//Node* lowestCommonAncestor(Node* root, Node* p, Node* q)
//{
//	if (root == p || q == root)
//		return root;
//	bool pleft = exists(root->left, p);
//	bool qleft = exists(root->left, q);
//	if (pleft&&qleft)
//		return lowestCommonAncestor(root->left, p, q);
//	if (!pleft&&!qleft)
//		return lowestCommonAncestor(root->right, p, q);
//	return root;
//}
Node* createTree(char data)
{
	Node* root = NULL;
	root = (Node*)malloc(sizeof(Node));
	root->val = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}
Node* test()
{
	Node* a = createTree(5);
	Node* b = createTree(3);
	Node* c = createTree(8);
	Node* d = createTree(2);
	Node* e = createTree(4);
	Node* f = createTree(6);
	Node* g = createTree(9);
	Node* h = createTree(1);
	Node* i = createTree(7);

	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	d->left = h;
	f->right = i;
	return a;
}
//二叉搜索树转换为排序双向链表
Node* prev = NULL;
void toDList(Node* node)
{
	node->left = prev;
	if (prev != NULL)
	{
		prev->right = node;
	}
	prev = node;
}
void inorder(Node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		toDList(root);
		inorder(root->right);
	}
}
int main()
{
	Node* root = NULL;
	root = test();
	inorder(root);
	system("pause");
	return 0;
}