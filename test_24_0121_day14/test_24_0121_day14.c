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
    struct TreeNode* node2 = CreatTreeNode(0);
    struct TreeNode* node3 = CreatTreeNode(1);
    struct TreeNode* node4 = CreatTreeNode(0);
    struct TreeNode* node5 = CreatTreeNode(1);
    struct TreeNode* node6 = CreatTreeNode(0);

    node1->left = node2;
    node1->right = node4;
    node2->left = node3;
    node4->left = node5;
    node4->right = node6;

    return node1;
}

//1022. 从根到叶的二进制数之和
int dfs(struct TreeNode* root, int val)
{
    if (root == NULL)
    {
        return 0;
    }
    val = (val << 1) | root->val;
    if (root->left == NULL && root->right == NULL)
    {
        return val;
    }
    return dfs(root->left, val) + dfs(root->right, val);
}
int sumRootToLeaf(struct TreeNode* root)
{
    return dfs(root, 0);
}

//563. 二叉树的坡度
int dfs_2(struct TreeNode* root, int* ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int sumleft = dfs_2(root->left, ans);
    int sumright = dfs_2(root->right, ans);
    *ans += abs(sumleft - sumright);
    return sumleft + sumright + root->val;
}

int findTilt(struct TreeNode* root)
{
    int ans = 0;
    dfs_2(root, &ans);
    return ans;
}

int main()
{
    struct TreeNode* root = CreatTree();
    int ret = sumRootToLeaf(root);
    printf("%d\n", ret);
    return 0;
}