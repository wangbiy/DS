#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	char val;
}Node;
//二叉树创建字符串
char* _tree2str(Node* t, char* ret)
{
	if (NULL == t)
		return ret;
	char szValue[32] = { 0 };
	sprintf(szValue,"%d",t->val);
	strcat(ret, szValue);//追加
	if (NULL == t->left)
	{
		if (NULL == t->right)
			return ret;
		else
		{
			strcat(ret, "()");
		}
	}
	else
	{
		strcat(ret, "(");
		_tree2str(t->left, ret);
		strcat(ret, ")");
	}
	if (NULL == t->right)
		return ret;
	else
	{
		strcat(ret, "(");
		_tree2str(t->right, ret);
		strcat(ret, ")");
	}
	return ret;

}
char * tree2str(Node* t)
{
	char ret[100000];//先给个空间
	ret[0] = '\0';
	return _tree2str(t,ret);
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
	Node* a = createTree(1);
	Node* b = createTree(2);
	Node* c = createTree(3);
	Node* d = createTree(4);
	a->left = b;
	a->right = c;
	b->right = d;
	return a;
}
int main()
{
	Node* root = NULL;
	root = test();
	char* ret=tree2str(root);
	printf("%s", ret);
	printf("\n");
	system("pause");
	return;
}
