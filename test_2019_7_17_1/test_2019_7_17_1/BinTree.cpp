#include "BinTree.h"
BTNode* BuyBinTreeNode(char data)
{
	BTNode* node = NULL;
	node = (BTNode*)malloc(sizeof(BTNode));
	node->left = NULL;
	node->right = NULL;
	node->val = data;
	return node;
}
BTNode* _createBinTree(char* arr, int size, int* index)//ǰ���������������
{
	BTNode* root = NULL;
	if (*index < size&&arr[*index] != '#')
	{
		//���������
		root = BuyBinTreeNode(arr[*index]);
		(*index)++;
		//����������
		root->left = _createBinTree(arr, size, index);
		(*index)++;//�������������󴴽�������������Ҫ������
		//����������
		root->right = _createBinTree(arr, size, index);
	}
	return root;
}
BTNode* createBinTree(char* arr, int size)
{
	int index = 0;
	return _createBinTree(arr, size, &index);
}
void DestroyBinTree(BTNode** root)//�����������
{
	assert(*root);
	if (*root)
	{
		DestroyBinTree(&(*root)->left);
		DestroyBinTree(&(*root)->right);
		free(*root);
		*root = NULL;
	}
}
void PreOrderTraversal(BTNode* root)//�ݹ��������
{
	if (root == NULL)
		return;
	printf("%c ", root->val);
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}
void inOrderTraversal(BTNode* root)//�ݹ��������
{
	if (root == NULL)
		return;
	inOrderTraversal(root->left);
	printf("%c ", root->val);
	inOrderTraversal(root->right);
}
void postOrderTraversal(BTNode* root)//�ݹ�������
{
	if (root == NULL)
		return;
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	printf("%c ", root->val);
}
int MyMax(int a, int b)
{
	return a >= b ? a : b;
}
int GetHeight(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = GetHeight(root->left);
	int right = GetHeight(root->right);
	return MyMax(left, right) + 1;
}
int getNodeCount1(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = getNodeCount1(root->left);
	int right = getNodeCount1(root->right);
	return left + right + 1;
}
int count = 0;
int getNodeCount2(BTNode* root)
{
	if (root == 0)
		return 0;
	else
	{
		count++;
		getNodeCount2(root->left);
		getNodeCount2(root->right);
	}
	return count;
}
int GetLeafCount(BTNode* root)//��Ҷ�ӽڵ����
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL&&root->right == NULL)
		return 1;
	else
	{
		return GetLeafCount(root->left) + GetLeafCount(root->right);
	}
}
int getKlevelCount(BTNode* root, int k)//���k���ϵĽ�����
{
	assert(k >= 1);
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	else
	{
		return getKlevelCount(root->left, k - 1) + getKlevelCount(root->right, k - 1);
	}
}
BTNode* find(BTNode* root, char v)//����ֵΪv�Ľ�㣬���ؽڵ��ַ
{
	if (root == NULL)
		return NULL;
	else if (root->val == v)
	{
		return root;
	}
	else
	{
		BTNode* left = find(root->left, v);
		if (left != NULL)
			return left;
		else
		{
			BTNode* right = find(root->right, v);
			if (right != NULL)
				return right;
			else
				return NULL;
		}
	}
}
void levelOrderTraversal(BTNode* root)//�������
{
	if (root == NULL)
		return;
	std::queue<BTNode*> q;
	q.push(root);
	while (!q.empty())
	{
		BTNode* front = q.front();
		q.pop();
		printf("%c ", front->val);
		if (front->left != NULL)
		{
			q.push(front->left);
		}
		if (front->right != NULL)
		{
			q.push(front->right);
		}
	}
}
bool isCompleteTree(BTNode* root)//�ж���ȫ������
{
	if (root == NULL)
		return true;
	std::queue<BTNode*> q;
	q.push(root);
	while (true)
	{
		BTNode* front = q.front();
		q.pop();
		if (front == NULL)
			break;
		q.push(front->left);
		q.push(front->right);
	}
	while (!q.empty())
	{
		BTNode* front = q.front();
		q.pop();
		if (front != NULL)
			return false;
	}
	return true;
}
BTNode* copyBinTree(BTNode* root)
{
	BTNode* NewNode = NULL;//����һ���µĶ�����
	if (root)
	{
		//�ȿ��������
		NewNode = BuyBinTreeNode(root->val);
		NewNode->left = copyBinTree(root->left);
		NewNode->right = copyBinTree(root->right);
	}
	return NewNode;
}