#include "BinTree.h"
BTNode* BuyBinTreeNode(BTDataType data)
{
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}
BTNode* _CreateBinTree(BTDataType* array, int size, int* index)//����ǰ���������������
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
BTNode* CreateBinTree(BTDataType* array, int size)//����������
{
	int index = 0;
	return _CreateBinTree(array, size, &index);
}
BTNode* CopyBinTree(BTNode* pRoot)//����������
{
	BTNode* pNewRoot = NULL;//����һ���µĶ�����
	if (pRoot)
	{
		pNewRoot = BuyBinTreeNode(pRoot->_data);//�ȿ��������
		pNewRoot->_pLeft = CopyBinTree(pRoot->_pLeft);//����������
		pNewRoot->_pRight = CopyBinTree(pRoot->_pRight);//����������
	}
	return pNewRoot;
}
void DestroyBinTree(BTNode** pRoot)//���ٶ�����,���ú������,��Ϊ�ı���ָ��ָ���������ö���ָ��
{
	assert(*pRoot);
	if (*pRoot)
	{
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;//�ı���ָ��ָ��
	}
}
void PreOrder(BTNode* pRoot)//ǰ������ݹ�
{
	if (pRoot == NULL)
		return;
	printf("%c ", pRoot->_data);//��
	PreOrder(pRoot->_pLeft);//������
	PreOrder(pRoot->_pRight);//������
}
void InOrder(BTNode* pRoot) //��������ݹ�
{
	if (pRoot == NULL)
		return;
	InOrder(pRoot->_pLeft);//������
	printf("%c ", pRoot->_data);//��
	InOrder(pRoot->_pRight);//������
}
void PostOrder(BTNode* pRoot)//��������ݹ�
{
	if (pRoot == NULL)
		return;
	PostOrder(pRoot->_pLeft);//������
	PostOrder(pRoot->_pRight);//������
	printf("%c ", pRoot->_data);//��
}
#include<stack>
void PreOrderNor(BTNode* pRoot)//ǰ������ǵݹ�
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
void InOrderNor(BTNode* pRoot)//��������ǵݹ�
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
void PostOrderNor(BTNode* pRoot)//��������ǵݹ�
{
	BTNode* cur = pRoot;
	BTNode* last = NULL;//��һ���������������������Ľ��
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
void LevelOrder(BTNode* pRoot)//�������
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
int GetNodeCount1(BTNode* pRoot)//��ȡ�������нڵ�ĸ�������1
{
	if (pRoot == NULL)
		return 0;
	int left = GetNodeCount1(pRoot->_pLeft);
	int right = GetNodeCount1(pRoot->_pRight);
	return left + right + 1;
}
int count = 0;
int GetNodeCount2(BTNode* pRoot)//��ȡ�������нڵ�ĸ�������2
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
int Height(BTNode* pRoot)// ��������ĸ߶�
{
	if (pRoot == NULL)
		return 0;
	int left = Height(pRoot->_pLeft);
	int right = Height(pRoot->_pRight);
	return _Max(left, right) + 1;
}
int GetLeafNodeCount(BTNode* pRoot)// ��ȡ��������Ҷ�ӽڵ�ĸ���
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
bool IsBalanceTree(BTNode* pRoot)// ���������Ƿ�ƽ��O(N^2)
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
bool IsBalanceTree_P(BTNode* pRoot, int* height)// ���������Ƿ�ƽ��O(N)
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
int GetKLevelNodeCount(BTNode* pRoot, int K)// ��ȡ��������K��ڵ�ĸ��� 
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
BTNode* find(BTNode* pRoot, char v)//����ֵΪv�Ľ�㣬���ؽڵ��ַ
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

BTNode* GetNodeParent(BTNode* pRoot, BTNode* pNode)// ��ȡ��������ĳ���ڵ��˫�׽ڵ�
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
bool Mirror(BTNode* s, BTNode* t)// �ж϶������ľ��� 
{
	if (s == NULL&&t == NULL)
		return true;
	if (s == NULL || t == NULL)
		return false;
	return s->_data == t->_data && Mirror(s->_pLeft, t->_pRight) && Mirror(s->_pRight, t->_pLeft);
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
	printf("�����������ɹ�!\n");
	BTNode* NewNode = CopyBinTree(a);
	printf("�����ɹ�!\n");
	printf("������a����������Ϊ:");
	PreOrder(a);
	printf("\n");
	printf("�����Ķ���������������Ϊ:");
	PreOrder(NewNode);
	printf("\n");
	printf("������a��������Ϊ:");
	InOrder(a);
	printf("\n");
	printf("�����Ķ���������������Ϊ:");
	InOrder(NewNode);
	printf("\n");
	printf("������a��������Ϊ:");
	PostOrder(a);
	printf("\n");
	printf("�����Ķ������ĺ�������Ϊ:");
	PostOrder(NewNode);
	printf("\n");
	printf("ǰ������ǵݹ�:");
	PreOrderNor(a);
	printf("\n");
	printf("��������ǵݹ�:");
	InOrderNor(a);
	printf("\n");
	printf("��������ǵݹ�:");
	PostOrderNor(a);
	printf("\n");
	printf("�������:");
	LevelOrder(a);
	printf("\n");
	ret = GetNodeCount1(a);//����1
	printf("������Ϊ:%d\n", ret);
	ret = GetNodeCount2(a);//����2
	printf("������Ϊ:%d\n", ret);
	ret = Height(a);
	printf("�������߶�Ϊ:%d\n", ret);
	ret = GetLeafNodeCount(a);
	printf("������Ҷ�ӽ�����Ϊ;%d\n", ret);
	bool result = IsBalanceTree(a);
	if (result == true)
		printf("��ƽ�������(����1)!\n");
	if (result == false)
		printf("����ƽ�������(����1)!\n");
	result = IsBalanceTree_P(a, &height);
	if (result == true)
		printf("��ƽ�������(����2)!\n");
	if (result == false)
		printf("����ƽ�������(����2)!\n");
	ret = GetKLevelNodeCount(a, 3);
	printf("��ȡ������Ľ�����Ϊ:%d\n", ret);
	BTNode* pParent = GetNodeParent(a, find(a, 'D'));
	pParent = GetNodeParent(a, find(a, 'F'));
	BTNode* t = NULL;
	char* _str = "ACG##F##BEH###D##";//���й���һ����aΪ�������
	t = CreateBinTree(_str, strlen(_str));
	result = Mirror(a, t);
	if (result == true)
		printf("a��t��Ϊ����!\n");
	if (result == false)
		printf("a��t����Ϊ����!\n");
	result=isCompleteTree(a);
	if (result == true)
		printf("����ȫ������!\n");
	if (result == false)
		printf("������ȫ������!\n");
}