#include "BinTree.h"
int main()
{
	BTNode* a = NULL;
	char* str = "ABD##E#H##CF##G##";
	a = createBinTree(str, strlen(str));
	printf("创建二叉树成功!\n");
	printf("先序排列为:");
	PreOrderTraversal(a);
	printf("\n");
	printf("中序排列为:");
	inOrderTraversal(a);
	printf("\n");
	printf("后序排列为:");
	postOrderTraversal(a);
	printf("\n");
	int height = GetHeight(a);
	printf("二叉树的高度为:%d\n", height);
	int count1 = getNodeCount1(a);
	printf("第一种方法二叉树的结点个数为:%d\n", count1);
	int count2 = getNodeCount2(a);
	printf("第二种方法二叉树的结点个数为:%d\n", count2);
	printf("二叉树的叶子结点个数为:%d\n", GetLeafCount(a));
	printf("第三层上的节点个数为:%d\n", getKlevelCount(a, 3));
	BTNode* ret = find(a, 'H');
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
