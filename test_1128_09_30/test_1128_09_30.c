#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

void preorder(struct TreeNode* root, int* returnSize, int* array)
{
    if (root == NULL)
    {
        return;
    }
    array[(*returnSize)++] = root->val;
    preorder(root->left, returnSize, array);
    preorder(root->right, returnSize, array);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* preArray = (int*)malloc(sizeof(int) * 101);
    *returnSize = 0;
    preorder(root, returnSize, preArray);
    return preArray;
}

