#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};
struct TreeNode* CreatTreeNode(int x)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    assert(node);

    node->val = x;
    node->left = node->right = NULL;
    return node;
}

struct TreeNode* CreatTree()
{
    struct TreeNode* node1 = CreatTreeNode(1);
    struct TreeNode* node2 = CreatTreeNode(2);
    struct TreeNode* node3 = CreatTreeNode(3);
    struct TreeNode* node4 = CreatTreeNode(4);
    struct TreeNode* node5 = CreatTreeNode(5);
    struct TreeNode* node6 = CreatTreeNode(6);

    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    node4->left = node5;
    node4->right = node6;

    return node1;
}


//BM24 二叉树的中序遍历
//递归
int TreeNodeNumber(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return TreeNodeNumber(root->left) + TreeNodeNumber(root->right) + 1;
}
void InOrder(int* arr, int* returnSize, struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(arr, returnSize, root->left);
    arr[(*returnSize)++] = root->val;
    InOrder(arr, returnSize, root->right);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int n = TreeNodeNumber(root);
    int* arr = (int*)malloc(sizeof(int) * n);
    InOrder(arr, returnSize, root);
    return arr;
}

//BM25 二叉树的后序遍历
void PostOrder(int* arr, int* returnSize, struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }

    PostOrder(arr, returnSize, root->left);
    PostOrder(arr, returnSize, root->right);
    arr[(*returnSize)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int n = TreeNodeNumber(root);
    int* arr = (int*)malloc(sizeof(int) * n);
    PostOrder(arr, returnSize, root);
    return arr;
}

//BM28 二叉树的最大深度
int maxDepth(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftnum = maxDepth(root->left);
    int rightnum = maxDepth(root->right);
    return leftnum > rightnum ? leftnum + 1 : rightnum + 1;
}

int main()
{
    struct TreeNode* root = CreatTree();
    int size = 0;
    int* arr = postorderTraversal(root, &size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    int num = maxDepth(root);
    printf("%d", num);
    return 0;
}