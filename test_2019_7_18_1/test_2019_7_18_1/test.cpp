#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
}Node;
////找最近公共祖先
Node* lowestCommonAncestor(Node* root, Node* p,Node* q)
{
   if (root == p || root == q || !root)//p或者q为根结点，那么最近公共祖先为根结点
		return root;

	Node* left = lowestCommonAncestor(root->left, p, q);
	Node* right = lowestCommonAncestor(root->right, p, q);
	if (!left&&!right)//左右子树均没有p或q
		return NULL;
	else if (left&&!right)//左子树可以找到但右子树找不到
		return left;
	else if (right&&!left)//右子树上能找到，但是左子树上找不到
		return right;
	return root;//左右子树都可以找到，即p和q分居根结点两侧
}
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
