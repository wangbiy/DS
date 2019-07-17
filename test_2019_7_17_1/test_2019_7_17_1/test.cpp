#include "BinTree.h"
int main()
{
	BTNode* a = NULL;
	char* str = "ABD##E#H##CF##G##";
	a = createBinTree(str, strlen(str));
	printf("�����������ɹ�!\n");
	printf("��������Ϊ:");
	PreOrderTraversal(a);
	printf("\n");
	printf("��������Ϊ:");
	inOrderTraversal(a);
	printf("\n");
	printf("��������Ϊ:");
	postOrderTraversal(a);
	printf("\n");
	int height = GetHeight(a);
	printf("�������ĸ߶�Ϊ:%d\n", height);
	int count1 = getNodeCount1(a);
	printf("��һ�ַ����������Ľ�����Ϊ:%d\n", count1);
	int count2 = getNodeCount2(a);
	printf("�ڶ��ַ����������Ľ�����Ϊ:%d\n", count2);
	printf("��������Ҷ�ӽ�����Ϊ:%d\n", GetLeafCount(a));
	printf("�������ϵĽڵ����Ϊ:%d\n", getKlevelCount(a, 3));
	BTNode* ret = find(a, 'H');
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
