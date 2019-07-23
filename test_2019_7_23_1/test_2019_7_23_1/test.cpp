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
	//������ڵ�,�����ڵ������ת��Ϊ�ַ���
	sprintf(szValue, "%d", t->val);
	strcat(ret, szValue);//׷�ӽ�ret
	if (t->left == NULL)//�ж�����������������ڣ��ж�������
	{
		if (t->right == NULL)//������Ҳ�����ڣ�ֱ�ӷ���ret
			return ret;
		else
		{
			strcat(ret, "()");//���������ڣ����׷������
		}
	}
	else//����������
	{
		strcat(ret, "(");//���׷��������
		_treetostr(t->left, ret);
		strcat(ret, ")");//�ݹ���ɺ�������������ɣ�׷��������
	}
	if (NULL == t->right)//�ж�������
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
	if (root == p || root == q || !root)//p����qΪ����㣬��ô�����������Ϊ�����
		return root;

	BTNode* left = lowestCommonAncestor(root->left, p, q);
	BTNode* right = lowestCommonAncestor(root->right, p, q);
	if (!left&&!right)//����������û��p��q
		return NULL;
	else if (left&&!right)//�����������ҵ����������Ҳ���
		return left;
	else if (right&&!left)//�����������ҵ����������������Ҳ���
		return right;
	return root;//���������������ҵ�����p��q�־Ӹ��������
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