#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int TreeDataType;
typedef struct TreeNode
{
	TreeDataType val;
	struct TreeNode* left;
	struct TreeNode* right;
}TNode;

TNode* CreatTreeNode(TreeDataType x)
{
	TNode* node = (TNode*)malloc(sizeof(TNode));
	assert(node);

	node->val = x;
	node->left = node->right = NULL;
	return node;
}

TNode* CreatTree()
{
	TNode* node1 = CreatTreeNode(1);
	TNode* node2 = CreatTreeNode(2);
	TNode* node3 = CreatTreeNode(3);
	TNode* node4 = CreatTreeNode(4);
	TNode* node5 = CreatTreeNode(5);
	TNode* node6 = CreatTreeNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

void PreOrder(TNode* node)
{
	//前序递归遍历
	if (node == NULL)
	{
		printf("N ");
		return;
	}
	printf("%d ", node->val);
	PreOrder(node->left);
	PreOrder(node->right);
}

void InOrder(TNode* node)
{
	//中序递归遍历
	if (node == NULL)
	{
		printf("N ");
		return;
	}
	InOrder(node->left);
	printf("%d ", node->val);
	InOrder(node->right);
}

void PostOrder(TNode* node)
{
	//后续递归遍历
	if (node == NULL)
	{
		printf("N ");
		return;
	}
	PostOrder(node->left);
	PostOrder(node->right);
	printf("%d ", node->val);
}

int TreeSize(TNode* node)
{
	//方案一，定义全局的变量
	//方案二
	return node == NULL ? 0 : TreeSize(node->left) + TreeSize(node->right) + 1;
}

int TreeLeafSize(TNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	if (node->left == NULL && node->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(node->left) + TreeLeafSize(node->right);
}

int TreeLevelKSize(TNode* node, int k)
{
	assert(k > 0);
	if (node == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeLevelKSize(node->left, k - 1) + TreeLevelKSize(node->right, k - 1);
}

int TreeHight(TNode* node)
{
	if (node == NULL)
	{
		return 0;
	}
	int lefthight = TreeHight(node->left);
	int righthight = TreeHight(node->right);

	return lefthight > righthight ? lefthight + 1 : righthight + 1;
}

int main()
{
	TNode* Tree = CreatTree();
	PreOrder(Tree);
	printf("\n");
	InOrder(Tree);
	printf("\n");
	PostOrder(Tree);
	printf("\n");

	printf("%d\n", TreeSize(Tree));
	printf("%d\n", TreeLeafSize(Tree));
	printf("%d\n", TreeHight(Tree));
	printf("%d\n", TreeLevelKSize(Tree, 2));
	return 0;
}