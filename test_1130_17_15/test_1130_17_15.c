#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

struct TreeNode 
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

//力扣226.翻转二叉树
void Swap(struct TreeNode** p1, struct TreeNode** p2)
{
	struct TreeNode* tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

struct TreeNode* invertTree(struct TreeNode* root)
{
	//默认是满二叉树
	if (root == NULL)
	{
		return NULL;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return root;
	}
	Swap(&root->left, &root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

//力扣572.另一棵树的子树
bool compare(struct TreeNode* root, struct TreeNode* subRoot)
{
	if (root == NULL && subRoot == NULL)
	{
		return true;
	}
	if (root == NULL || subRoot == NULL)
	{
		return false;
	}
	if (root->val != subRoot->val)
	{
		return false;
	}
	return compare(root->left, subRoot->left) && compare(root->right, subRoot->right);
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
	if (root == NULL)
	{
		return false;
	}
	bool ret = compare(root, subRoot);
	if (ret == false)
	{
		return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
	}
	return ret;
}

//牛客网KY11 二叉树遍历









typedef int TreeDataType;
typedef struct TreeNode
{
	TreeDataType val;
	struct TreeNode* left;
	struct TreeNode* right;
}TNode;
TNode* BinaryTreeFind(TNode* root, TreeDataType x)
{
	//会出现问题，递归并没有全部返回
	if (root == NULL)
	{
		return;
	}
	if (root->val == x)
	{
		return root;
	}
	TNode* ret1 = BinaryTreeFind(root->left, x);
	if (ret1)
	{
		return ret1;
	}
	TNode* ret2 = BinaryTreeFind(root->right, x);
	if (ret2)
	{
		return ret2;
	}
	return NULL;
}