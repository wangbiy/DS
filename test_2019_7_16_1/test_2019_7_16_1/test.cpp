#include <stdio.h>
#include <stdlib.h>
//����������������
//1.��������ǰ�����
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
}Node;
Node* createNode(char ch)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = ch;
	node->left = node->right = NULL;
	return node;
}
Node* test1()
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
Node* test2()
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
Node* test3()
{
	Node* c = createNode('C');
	Node* f = createNode('F');
	Node* g = createNode('G');
	c->left = f;
	c->right = g;
	return c;
}
int *arr = NULL;
int size = 0;
void preorder(Node* root)
{
	if (root == NULL)
		return;
	arr[size++] = root->val;//β��
	preorder(root->left);
	preorder(root->right);
}
int* preQrderTraversal(Node* root, int* returnsize)
{
	arr = (int*)malloc(sizeof(int)* 10000);
	size = 0;
	preorder(root);
	*returnsize = size;
	return arr;
}
//2.���������������
void inorder(Node* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	arr[size++] = root->val;//β��
	inorder(root->right);
}
int* inOrderTraversal(Node* root, int* returnsize)
{
	arr = (int*)malloc(sizeof(int)* 10000);
	size = 0;
	inorder(root);
	*returnsize = size;
	return arr;
}
//3.�������ĺ������
void postorder(Node* root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	arr[size++] = root->val;//β��
}
int* postOrderTraversal(Node* root, int* returnSize)
{
	arr = (int*)malloc(sizeof(int)* 10000);
	size = 0;
	postorder(root);
	*returnSize = size;
	return arr;
}
//4.����������Ƿ���ͬ
bool isSameTree(Node* p, Node* q)
{
	if (p == NULL&&q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	return p->val == q->val&&isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
//5.��һ����������
bool find(Node* root, Node* t)
{
	if (root == NULL)
		return false;
	if (root->val == t->val)
	{
		if (isSameTree(root, t))
			return true;
	}
		bool left = find(root->left, t);
		if (left == true)
		{
			return true;
		}
		return find(root->right, t);
}
bool isSubTree(Node* s, Node* t)
{
	return find(s, t);
}
//6.�ж�һ�����Ƿ�Ϊƽ�������
int myMax(int a, int b)
{
	return a >= b ? a : b;
}
int getHeight(Node* root)
{
	if (root == NULL)
		return 0;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return myMax(left, right) + 1;
}
bool isBalancedTree(Node* root)
{
	if (root == NULL)
		return true;
	if (isBalancedTree(root->left) == false)
		return false;
	if (isBalancedTree(root->right) == false)
		return false;
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	int diff = left - right;
	if (diff<-1 || diff>1)
	{
		return false;
	}
	return true;
}
//7.�Գƶ�����
bool isMirror(Node* s, Node* t)
{
	if (s == NULL&&t == NULL)
		return true;
	if (s == NULL || t == NULL)
		return false;
	return s->val == t->val&&isMirror(s->left, t->right) && isMirror(s->right, t->left);
}
bool isSymmetric(Node* root)
{
	if (root == NULL)
		return true;
	return isMirror(root->left, root->right);
}
int main()
{
	Node* p = NULL;
	Node* q = NULL;
	p = test1();
	q = test2();
	if (isSameTree(p, q) == true)
	{
		printf("p��q����ͬ�Ķ�����!\n");
	}
	if (isSameTree(p, q) == false)
		printf("p��q������ͬ�Ķ�����!\n");
	Node* s = NULL;
	Node* t = NULL;
	s = test1();
	t = test3();
	if (isSubTree(s, t) == true)
		printf("t��s������!\n");
	if (isSubTree(s, t) == false)
		printf("t����t������!\n");
	if (isBalancedTree(s) == true)
		printf("s��ƽ�������!\n");
	if (isBalancedTree(s) == false)
		printf("s����ƽ�������!\n");
	if (isSymmetric(s) == true)
		printf("s�ǶԳƶ�����!\n");
	if (isSymmetric(s) == false)
		printf("s���ǶԳƶ�����!\n");
	system("pause");
	return 0;
}



