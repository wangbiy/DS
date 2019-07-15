//二叉树的操作
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
void PreOrderTraversal(Node* root)//递归先序遍历
{
	if (root == NULL)
		return;
	printf("%c ", root->val);
	PreOrderTraversal(root->left);
	PreOrderTraversal(root->right);
}
void inOrderTraversal(Node* root)//递归中序遍历
{
	if (root == NULL)
		return;
	inOrderTraversal(root->left);
	printf("%c ", root->val);
	inOrderTraversal(root->right);
}
void postOrderTraversal(Node* root)//递归后序遍历
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
int GetLeafCount(Node* root)//求叶子节点个数
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
int getKlevelCount(Node* root, int k)//求第k层上的结点个数
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
Node* find(Node* root, char v)//查找值为v的结点，返回节点地址
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
void levelOrderTraversal(Node* root)//层序遍历
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
bool isCompleteTree(Node* root)//判断完全二叉树
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
	printf("先序排列为:");
	PreOrderTraversal(a);
	printf("\n");
	printf("中序排列为:");
	inOrderTraversal(a);
	printf("\n");
	printf("后序排列为:");
	postOrderTraversal(a);
	printf("\n");
	int height=GetHeight(a);
	printf("二叉树的高度为:%d\n",height);
	int count1 = getNodeCount1(a);
	printf("第一种方法二叉树的结点个数为:%d\n", count1);
	int count2 = getNodeCount2(a);
	printf("第二种方法二叉树的结点个数为:%d\n", count2);
	printf("二叉树的叶子结点个数为:%d\n", GetLeafCount(a));
	printf("第三层上的节点个数为:%d\n", getKlevelCount(a, 3));
	Node* ret = find(a, 'H');
	printf("查找值为'H'的结点地址为%p\n", ret);
	printf("层序遍历");
	levelOrderTraversal(a);
	printf("\n");
	if (isCompleteTree(a))
		printf("是完全二叉树!\n");
	else
		printf("不是完全二叉树!\n");
	system("pause");
	return 0;
}
