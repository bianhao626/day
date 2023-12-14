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
    struct TreeNode* node1 = CreatTreeNode(5);
    struct TreeNode* node2 = CreatTreeNode(4);
    struct TreeNode* node3 = CreatTreeNode(8);
    struct TreeNode* node4 = CreatTreeNode(1);
    struct TreeNode* node5 = CreatTreeNode(11);
    struct TreeNode* node6 = CreatTreeNode(9);
    struct TreeNode* node7 = CreatTreeNode(2);
    struct TreeNode* node8 = CreatTreeNode(7);

    node1->left = node2;
    node1->right = node3;

    node2->left = node4;
    node2->right = node5;

    node3->right = node6;

    node5->left = node7;
    node5->right = node8;

    return node1;
}

//BM29 二叉树中和为某一值的路径(一)
//存在空间浪费的情况，计算的是树中所有的节点的个数，改进思路是计算所有叶子节点的个数
int TreeNodeNumber_1(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return TreeNodeNumber_1(root->left) + TreeNodeNumber_1(root->right) + 1;
}
int TreeNodeNumber_2(struct TreeNode* root)
{
    //计算叶子节点的个数
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return TreeNodeNumber_2(root->left) + TreeNodeNumber_2(root->right);
}
void PreOrder(int* arr, struct TreeNode* root, int* i, int* s)
{
    if (root == NULL)
    {
        return;
    }
    *s += root->val;
    
    PreOrder(arr, root->left, i, s);
    PreOrder(arr, root->right, i, s);
    if (root->left == NULL && root->right == NULL)
    {
        arr[(*i)++] = *s;
    }
    *s -= root->val;
}
bool hasPathSum(struct TreeNode* root, int sum)
{
    if (root == NULL)
    {
        return false;
    }
    //int size = TreeNodeNumber_1(root);
    int size = TreeNodeNumber_2(root);
    int* arr = (int*)malloc(sizeof(int) * size);
    int i = 0;
    int s = 0;
    PreOrder(arr, root, &i, &s);
    for (int j = 0; j < i; j++)
    {
        if (sum == arr[j])
        {
            return true;
        }
    }
    return false;
}


int main()
{
    struct TreeNode* root = CreatTree();
    int sum = 22;
    bool ret = hasPathSum(root, sum);
    printf("%d\n", ret);

    return 0;
}