#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct BinTreeNode
{
	char val;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
}BTNode;
char* _treetostr(BTNode* t, char* ret)
{
	if (t == NULL)
		return ret;
	char szValue[32] = { 0 };
	//处理根节点,将根节点的数据转换为字符串
	sprintf(szValue, "%d", t->val);
	strcat(ret, szValue);//追加进ret
	if (t->left == NULL)//判断左子树，如果不存在，判断右子树
	{
		if (t->right == NULL)//右子树也不存在，直接返回ret
			return ret;
		else
		{
			strcat(ret, "()");//右子树存在，向后追加括号
		}
	}
	else//左子树存在
	{
		strcat(ret, "(");//向后追加左括号
		_treetostr(t->left, ret);
		strcat(ret, ")");//递归完成后即左子树处理完成，追加右括号
	}
	if (NULL == t->right)//判断右子树
		return ret;
	else
	{
		strcat(ret, "(");
		_treetostr(t->right, ret);
		strcat(ret, ")");
	}
	return ret;
}
char* treetostr(BTNode* t)
{
	char ret[100000];
	ret[0] = '\0';
	return _treetostr(t, ret);
}
BTNode* createTreeNode(char data)
{
	BTNode* root = NULL;
	root = (BTNode*)malloc(sizeof(BTNode));
	root->val = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}
BTNode* test()
{
	BTNode* a = createTreeNode(1);
	BTNode* b = createTreeNode(2);
	BTNode* c = createTreeNode(3);
	BTNode* d = createTreeNode(4);
	a->left = b;
	a->right = c;
	b->right = d;
	return a;
}
BTNode* lowestCommonAncestor(BTNode* root, BTNode* p, BTNode* q)
{
	if (root == p || root == q || !root)//p或者q为根结点，那么最近公共祖先为根结点
		return root;

	BTNode* left = lowestCommonAncestor(root->left, p, q);
	BTNode* right = lowestCommonAncestor(root->right, p, q);
	if (!left&&!right)//左右子树均没有p或q
		return NULL;
	else if (left&&!right)//左子树可以找到但右子树找不到
		return left;
	else if (right&&!left)//右子树上能找到，但是左子树上找不到
		return right;
	return root;//左右子树都可以找到，即p和q分居根结点两侧
}
int main()
{
	BTNode* a = test();
	char* result = treetostr(a);
	printf("%s\n", result);
	BTNode* p = createTreeNode(1);
	BTNode* q = createTreeNode(4);
	BTNode* ret=lowestCommonAncestor(a, p, q);
	system("pause");
	return 0;
}