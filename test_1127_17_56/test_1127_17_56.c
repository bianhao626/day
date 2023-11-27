#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>


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
	TNode* node1 = CreatTreeNode(9);
	TNode* node2 = CreatTreeNode(9);
	TNode* node3 = CreatTreeNode(6);
	TNode* node4 = CreatTreeNode(9);
	TNode* node5 = CreatTreeNode(9);
	/*TNode* node6 = CreatTreeNode(6);*/

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	/*node4->right = node6;*/

	return node1;
}


int maxDepth(struct TreeNode* root) {
	if (root == NULL)
	{
		return 0;
	}
	int leftheight = maxDepth(root->left);
	int rightheight = maxDepth(root->right);

	return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
	//关键问题在于如何拆分子问题
	if (p == NULL && q == NULL)
	{
		return true;
	}
	else if (p == NULL || q == NULL)
	{
		return false;
	}
	else if (p->val != q->val)
	{
		return false;
	}
	else
	{
		return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
}

bool isUnivalTree(struct TreeNode* root) {
	if (root == NULL)
	{
		return true;
	}
	if (root->left != NULL)
	{
		if (root->val != root->left->val)
		{
			return false;
		}
	}
	if (root->right != NULL)
	{
		if (root->val != root->right->val)
		{
			return false;
		}
	}
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}

int main()
{
	TNode* root = CreatTree();

	/*printf("%d\n", maxDepth(root));*/
	printf("%d", isUnivalTree(root));
	return 0;
}