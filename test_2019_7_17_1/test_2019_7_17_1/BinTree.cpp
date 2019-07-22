#include "BinTree.h"
BTNode* BuyBinTreeNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}
BTNode* _CreateBinTree(BTDataType* array, int size, int* index)//根据前序遍历创建二叉树
{
	BTNode* root = NULL;
	if (*index < size && array[*index] != '#')
	{
		root = BuyBinTreeNode(array[*index]);
		(*index)++;
		root->_pLeft = _CreateBinTree(array, size, index);
		(*index)++;
		root->_pRight = _CreateBinTree(array, size, index);
	}
	return root;
}
BTNode* CreateBinTree(BTDataType* array, int size)//创建二叉树
{
	int index = 0;
	return _CreateBinTree(array, size, &index);
}
BTNode* CopyBinTree(BTNode* pRoot)//拷贝二叉树
{
	BTNode* pNewRoot = NULL;//定义一个新的二叉树
	if (pRoot)
	{
		pNewRoot = BuyBinTreeNode(pRoot->_data);//先拷贝根结点
		pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);//拷贝左子树
		pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);//拷贝右子树
	}
	return pNewRoot;
}
void DestroyBinTree(BTNode** pRoot)//销毁二叉树,利用后序遍历,因为改变了指针指向，所以利用二级指针
{
	assert(*pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;//改变了指针指向
	}
}
void PreOrder(BTNode* pRoot)//前序遍历递归
{
	if (pRoot == NULL)
		return;
	printf("%c ", pRoot->_data);//根
	PreOrder(pRoot->_pLeft);//左子树
	PreOrder(pRoot->_pRight);//右子树
}
void InOrder(BTNode* pRoot) //中序遍历递归
{
	if (pRoot == NULL)
		return;
	InOrder(pRoot->_pLeft);//左子树
	printf("%c ", pRoot->_data);//根
	InOrder(pRoot->_pRight);//右子树
}
void PostOrder(BTNode* pRoot)//后序遍历递归
{
	if (pRoot == NULL)
		return;
	PostOrder(pRoot->_pLeft);//左子树
	PostOrder(pRoot->_pRight);//右子树
	printf("%c ", pRoot->_data);//根
}
#include<stack>
void PreOrderNor(BTNode* pRoot)//前序遍历非递归
{
	BTNode* cur = pRoot;
	std::stack<BTNode*> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			printf("%c ", cur->_data);
			st.push(cur);
			cur = cur->_pLeft;
		}
		BTNode* top = st.top();
		st.pop();
		cur = top->_pRight;
	}
}
void InOrderNor(BTNode* pRoot)//中序遍历非递归
{
	BTNode* cur = pRoot;
	std::stack<BTNode*> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->_pLeft;
		}
		BTNode* top = st.top();
		printf("%c ", top->_data);
		st.pop();
		cur = top->_pRight;
	}

}
void PostOrderNor(BTNode* pRoot)//后序遍历非递归
{
	BTNode* cur = pRoot;
	BTNode* last = NULL;//上一次左右子树都被遍历过的结点
	std::stack<BTNode*> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->_pLeft;
		}
		BTNode* top = st.top();
		if (top->_pRight == NULL || top->_pRight == last)
		{
			st.pop();
			printf("%c ", top->_data);
			last = top;
		}
		else
		{
			cur = top->_pRight;
		}
	}
}
#include <queue>
void LevelOrder(BTNode* pRoot)//层序遍历
{
	if (NULL == pRoot)
		return;
	std::queue<BTNode*> q;
	q.push(pRoot);
	while (!q.empty())
	{
		BTNode* front = q.front();
		q.pop();
		printf("%c ", front->_data);
		if (front->_pLeft != NULL)
		{
			q.push(front->_pLeft);
		}
		if (front->_pRight != NULL)
		{
			q.push(front->_pRight);
		}
	}
}
int GetNodeCount1(BTNode* pRoot)//获取二叉树中节点的个数方法1
{
	if (pRoot == NULL)
		return 0;
	int left = GetNodeCount1(pRoot->_pLeft);
	int right = GetNodeCount1(pRoot->_pRight);
	return left + right + 1;
}
int count = 0;
int GetNodeCount2(BTNode* pRoot)//获取二叉树中节点的个数方法2
{
	if (pRoot == 0)
		return 0;
	else
	{
		count++;
		GetNodeCount2(pRoot->_pLeft);
		GetNodeCount2(pRoot->_pRight);
	}
	return count;
}
int _Max(int a, int b)
{
	return a >= b ? a : b;
}
int Height(BTNode* pRoot)// 求二叉树的高度
{
	if (pRoot == NULL)
		return 0;
	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);
	return _Max(left, right) + 1;
}
int GetLeafNodeCount(BTNode* pRoot)// 获取二叉数中叶子节点的个数
{
	if (pRoot == NULL)
		return 0;
	else if (pRoot->_pLeft == NULL&&pRoot->_pRight == NULL)
		return 1;
	else
	{
		return GetLeafNodeCount(pRoot->_pLeft) + GetLeafNodeCount(pRoot->_pRight);
	}
}
bool IsBalanceTree(BTNode* pRoot)// 检测二叉树是否平衡O(N^2)
{
	if (pRoot == NULL)
		return true;
	if (pRoot->_pLeft == false)
		return false;
	if (pRoot->_pRight == false)
		return true;
	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);
	int diff = left - right;
	if (diff > 1 || diff < -1)
		return false;
	return true;
}
bool IsBalanceTree_P(BTNode* pRoot, int* height)// 检测二叉树是否平衡O(N)
{
	int IsLbalance = 0;
	int IsRbalance = 0;
	int leftHeight = 0;
	int rightHeight = 0;
	if (pRoot == NULL)
		return true;
	IsLbalance = IsBalanceTree_P(pRoot->_pLeft, &leftHeight);
	IsRbalance = IsBalanceTree_P(pRoot->_pRight, &rightHeight);
	if (IsLbalance && IsRbalance && abs(rightHeight - leftHeight) < 2)
	{
		*height = leftHeight>rightHeight ? leftHeight + 1 : rightHeight + 1;
		return true;
	}
	return false;

}
int GetKLevelNodeCount(BTNode* pRoot, int K)// 获取二叉树第K层节点的个数 
{
	assert(K >= 1);
	if (pRoot == NULL)
		return 0;
	if (K == 1)
		return 1;
	else
	{
		return GetKLevelNodeCount(pRoot->_pLeft, K - 1) + GetKLevelNodeCount(pRoot->_pRight, K - 1);
	}
}
BTNode* find(BTNode* pRoot, char v)//查找值为v的结点，返回节点地址
{
	if (pRoot == NULL)
		return NULL;
	else if (pRoot->_data == v)
		return pRoot;
	else
	{
		BTNode* left = find(pRoot->_pLeft, v);
		if (left != NULL)
			return left;
		return find(pRoot->_pRight, v);
	}
}

BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode)// 获取二叉树中某个节点的双亲节点
{
	BTNode* pParent = NULL;
	if (pRoot == NULL || pNode == NULL)
		return NULL;
	if (pRoot == pNode)
		return NULL;
	if (pRoot->_pLeft == pNode || pRoot->_pRight == pNode)
		return pRoot;
	pParent = GetNodeParent(pRoot->_pLeft, pNode);
	if (pParent != NULL)
		return pParent;
	return GetNodeParent(pRoot->_pRight, pNode);
}
bool Mirror(BTNode* s, BTNode* t)// 判断二叉树的镜像 
{
	if (s == NULL&&t == NULL)
		return true;
	if (s == NULL || t == NULL)
		return false;
	return s->_data == t->_data && Mirror(s->_pLeft, t->_pRight) && Mirror(s->_pRight, t->_pLeft);
}
bool isCompleteTree(BTNode* root)//判断完全二叉树
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
		q.push(front->_pLeft);
		q.push(front->_pRight);
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
void test()
{
	BTNode* a = NULL;
	int ret = 0;
	int height = 0;
	char* str = "ABD##E#H##CF##G##";
	a = CreateBinTree(str, strlen(str));
	printf("创建二叉树成功!\n");
	BTNode* NewNode = CopyBinTree(a);
	printf("拷贝成功!\n");
	printf("二叉树a的先序排列为:");
	PreOrder(a);
	printf("\n");
	printf("拷贝的二叉树的先序排列为:");
	PreOrder(NewNode);
	printf("\n");
	printf("二叉树a中序排列为:");
	InOrder(a);
	printf("\n");
	printf("拷贝的二叉树的中序排列为:");
	InOrder(NewNode);
	printf("\n");
	printf("二叉树a后序排列为:");
	PostOrder(a);
	printf("\n");
	printf("拷贝的二叉树的后序排列为:");
	PostOrder(NewNode);
	printf("\n");
	printf("前序遍历非递归:");
	PreOrderNor(a);
	printf("\n");
	printf("中序遍历非递归:");
	InOrderNor(a);
	printf("\n");
	printf("后序遍历非递归:");
	PostOrderNor(a);
	printf("\n");
	printf("层序遍历:");
	LevelOrder(a);
	printf("\n");
	ret = GetNodeCount1(a);//方法1
	printf("结点个数为:%d\n", ret);
	ret = GetNodeCount2(a);//方法2
	printf("结点个数为:%d\n", ret);
	ret = Height(a);
	printf("二叉树高度为:%d\n", ret);
	ret = GetLeafNodeCount(a);
	printf("二叉树叶子结点个数为;%d\n", ret);
	bool result = IsBalanceTree(a);
	if (result == true)
		printf("是平衡二叉树(方法1)!\n");
	if (result == false)
		printf("不是平衡二叉树(方法1)!\n");
	result = IsBalanceTree_P(a, &height);
	if (result == true)
		printf("是平衡二叉树(方法2)!\n");
	if (result == false)
		printf("不是平衡二叉树(方法2)!\n");
	ret = GetKLevelNodeCount(a, 3);
	printf("获取第三层的结点个数为:%d\n", ret);
	BTNode* pParent = GetNodeParent(a, find(a, 'D'));
	pParent = GetNodeParent(a, find(a, 'F'));
	BTNode* t = NULL;
	char* _str = "ACG##F##BEH###D##";//自行构建一个与a为镜像的树
	t = CreateBinTree(_str, strlen(_str));
	result = Mirror(a, t);
	if (result == true)
		printf("a和t互为镜像!\n");
	if (result == false)
		printf("a和t不互为镜像!\n");
	result=isCompleteTree(a);
	if (result == true)
		printf("是完全二叉树!\n");
	if (result == false)
		printf("不是完全二叉树!\n");
}