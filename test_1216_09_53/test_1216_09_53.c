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

//BM33 二叉树的镜像
void Swap(struct TreeNode* root)
{
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}
struct TreeNode* Mirror(struct TreeNode* pRoot)
{
    if (pRoot == NULL)
    {
        return NULL;
    }
    Swap(pRoot);
    Mirror(pRoot->left);
    Mirror(pRoot->right);
    return pRoot;
}

//BM36 判断是不是平衡二叉树
int TreeHight(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftheight = TreeHight(root->left);
    int rightheight = TreeHight(root->right);
    return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
}
bool compare(struct TreeNode* root)
{
    int lefthight = TreeHight(root->left);
    int righthight = TreeHight(root->right);
    if (abs(lefthight - righthight) > 1)
    {
        return false;
    }
    else
    {
        return true;
    }

}
bool IsBalanced_Solution(struct TreeNode* pRoot)
{
    if (pRoot == NULL)
    {
        return true;
    }
    return compare(pRoot) && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
}

int main()
{
    struct TreeNode* root = CreatTree();
    struct TreeNode* ret = Mirror(root);
    printf("%d\n", IsBalanced_Solution(root));
    printf("%d\n", IsBalanced_Solution(root));
    return 0;
}