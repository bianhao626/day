#define _CRT_SECURE_NO_WARNINGS 1
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    char val;
    struct TreeNode* left;
    struct TreeNode* right;
}TNode;

TNode* CreatTree(char* arr, int* k)
{
    if (arr[*k] == '#')
    {
        (*k)++;
        return NULL;
    }
    TNode* root = (TNode*)malloc(sizeof(TNode));
    assert(root);
    root->val = arr[(*k)++];
    root->left = CreatTree(arr, k);
    root->right = CreatTree(arr, k);
    return root;
}

void InOrder(TNode* root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}

int main()
{
    char ch[101];
    scanf("%s", ch);
    int i = 0;
    //先序遍历创建树
    TNode* root = CreatTree(ch, &i);

    //中序遍历树
    InOrder(root);
    return 0;
}