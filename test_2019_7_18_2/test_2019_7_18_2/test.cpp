#include <stdio.h>
#include <stdlib.h>
#include <stack>
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	int val;
}Node;
Node* createTree(int data)
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
//非递归实现前序、中序、后序遍历
void preorderNOR(Node* root)
{
	Node* cur = root;
	std::stack<Node*> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			printf("%d", cur->val);
			st.push(cur);
			cur = cur->left;
		}
		Node* top = st.top();
		st.pop();
		cur = top->right;
	}
}
void inorderNOR(Node* root)
{
	Node* cur = root;
	std::stack<Node*> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}
		Node* top = st.top();
		printf("%d", top->val);
		st.pop();
		cur = top->right;
	}
}
void postorderNOR(Node* root)
{
	Node* cur = root;
	Node* last = NULL;//上一次被完整遍历过的结点
	std::stack<Node*> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}
		Node* top = st.top();
		if (top->right == NULL||top->right==last)
		{
			st.pop();
			printf("%d", top->val);
			last = top;
		}
		else
		{
			cur = top->right;
		}
	}
}
int main()
{
	Node* root = NULL;
	root = test();
	printf("前序遍历为:");
	preorderNOR(root);
	printf("\n");
	printf("中序遍历为:");
	inorderNOR(root);
	printf("\n");
	printf("后序遍历为:");
	postorderNOR(root);
	printf("\n");
	system("pause");
	return 0;
}