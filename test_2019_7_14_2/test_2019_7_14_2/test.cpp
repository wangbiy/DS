//�������Ĳ���
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef struct BinTreeNode
{
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	char val;
}Node;
Node* createNode(char ch)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = ch;
	node->left = node->right = NULL;
	return node;
}
Node* test()
{
	Node* a = createNode('A');
	Node* b = createNode('B');
	Node* c = createNode('C');
	Node* d = createNode('D');
	Node* e = createNode('E');
	Node* f = createNode('F');
	Node* g = createNode('G');
	Node* h = createNode('H');
	a->left = b;
	a->right = c;
	b->left = d;
	b->right = e;
	c->left = f;
	c->right = g;
	e->right = h;
	return a;
}
void PreOrderTraversal(Node* root)//�ݹ��������
{
	if (root == NULL)
		return;
	printf("%c ", root->val);
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}
void inOrderTraversal(Node* root)//�ݹ��������
{
	if (root == NULL)
		return;
	inOrderTraversal(root->left);
	printf("%c ", root->val);
	inOrderTraversal(root->right);
}
void postOrderTraversal(Node* root)//�ݹ�������
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
int GetHeight(Node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = GetHeight(root->left);
	int right = GetHeight(root->right);
	return MyMax(left, right) + 1;
}
int getNodeCount1(Node* root)
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
int getNodeCount2(Node* root)
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
int GetLeafCount(Node* root)//��Ҷ�ӽڵ����
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
int getKlevelCount(Node* root, int k)//���k���ϵĽ�����
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
Node* find(Node* root, char v)//����ֵΪv�Ľ�㣬���ؽڵ��ַ
{
	if (root == NULL)
		return NULL;
	else if (root->val==v)
	{
		return root;
	}
	else
	{
		Node* left = find(root->left, v);
		if (left != NULL)
			return left;
		else
		{
			Node* right = find(root->right, v);
			if (right != NULL)
				return right;
			else
				return NULL;
		}
	}
}
#include <queue>
void levelOrderTraversal(Node* root)//�������
{
	if (root == NULL)
		return;
	std::queue<Node*> q;
	q.push(root);
	while (!q.empty())
	{
		Node* front = q.front();
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
bool isCompleteTree(Node* root)//�ж���ȫ������
{
	if (root == NULL)
		return true;
	std::queue<Node*> q;
	q.push(root);
	while (true)
	{
		Node* front = q.front();
		q.pop();
		if (front == NULL)
			break;
		q.push(front->left);
		q.push(front->right);
	}
	while (!q.empty())
	{
		Node* front = q.front();
		q.pop();
		if (front != NULL)
			return false;
	}
	return true;
}
int main()
{
	Node* a = NULL;
	a=test();
	printf("��������Ϊ:");
	PreOrderTraversal(a);
	printf("\n");
	printf("��������Ϊ:");
	inOrderTraversal(a);
	printf("\n");
	printf("��������Ϊ:");
	postOrderTraversal(a);
	printf("\n");
	int height=GetHeight(a);
	printf("�������ĸ߶�Ϊ:%d\n",height);
	int count1 = getNodeCount1(a);
	printf("��һ�ַ����������Ľ�����Ϊ:%d\n", count1);
	int count2 = getNodeCount2(a);
	printf("�ڶ��ַ����������Ľ�����Ϊ:%d\n", count2);
	printf("��������Ҷ�ӽ�����Ϊ:%d\n", GetLeafCount(a));
	printf("�������ϵĽڵ����Ϊ:%d\n", getKlevelCount(a, 3));
	Node* ret = find(a, 'H');
	printf("����ֵΪ'H'�Ľ���ַΪ%p\n", ret);
	printf("�������");
	levelOrderTraversal(a);
	printf("\n");
	if (isCompleteTree(a))
		printf("����ȫ������!\n");
	else
		printf("������ȫ������!\n");
	system("pause");
	return 0;
}
