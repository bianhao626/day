#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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



//575. 分糖果
int cmp(const void* p1, const void* p2)
{
    return *(int*)p1 - *(int*)p2;
}
int distributeCandies(int* candyType, int candyTypeSize)
{
    int type = candyTypeSize / 2;
    int a = 1;
    qsort(candyType, candyTypeSize, sizeof(candyType[0]), cmp);
    for (int i = 1; i < candyTypeSize; i++)
    {
        if (candyType[i] != candyType[i - 1] && a < type)
        {
            a++;
        }
    }
    return a;
}

//1214代码
//112. 路径总和

//113. 路径总和 II
int** ret;
int retSize;
int* retColSize;

int* path;
int pathSize;

void dfs(struct TreeNode* root, int targetSum)
{
    if (root == NULL)
    {
        return;
    }

    path[pathSize++] = root->val;
    targetSum -= root->val;
    if (root->left == NULL && root->right == NULL && 0 == targetSum)
    {
        int* tmp = malloc(sizeof(int) * pathSize);
        memcpy(tmp, path, sizeof(int) * pathSize);
        ret[retSize] = tmp;
        retColSize[retSize++] = pathSize;
    }
    dfs(root->left, targetSum);
    dfs(root->right, targetSum);
    pathSize--;

}
int** pathSum(struct TreeNode* root, int targetSum, int* returnSize, int** returnColumnSizes)
{
    ret = malloc(sizeof(int*) * 2001);
    retColSize = malloc(sizeof(int) * 2001);
    path = malloc(sizeof(int) * 2001);
    retSize = pathSize = 0;

    dfs(root, targetSum);
    *returnColumnSizes = retColSize;
    *returnSize = retSize;
    return ret;
}

int main()
{
    int arr[6] = { 100,0,100,0,100,0 };
    int ret = distributeCandies(arr, 6);
    printf("%d\n", ret);
	return 0;
}