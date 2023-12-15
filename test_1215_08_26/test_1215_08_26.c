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

//BM31 对称的二叉树
bool isSymmetrical_1(struct TreeNode* p1, struct TreeNode* p2)
{
    if (p1 == NULL && p2 == NULL)
    {
        return true;
    }
    if (p1 == NULL || p2 == NULL)
    {
        return false;
    }
    if (p1->val != p2->val)
    {
        return false;
    }
    return isSymmetrical_1(p1->left, p2->right) && isSymmetrical_1(p1->right, p2->left);
}
bool isSymmetrical(struct TreeNode* pRoot)
{
    if (pRoot == NULL)
    {
        return true;
    }
    return isSymmetrical_1(pRoot->left, pRoot->right);
}

//BM32 合并二叉树
struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2)
{
    if (!t1 || !t2)
    {
        return t1 ? t1 : t2;
    }
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
}

int main()
{
    struct TreeNode* root = CreatTree();
    printf("%d\n",isSymmetrical(root));
    return 0;
}