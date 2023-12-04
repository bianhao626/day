//145. 二叉树的后序遍历
void PostOrder(struct TreeNode* root, int* returnSize, int* array)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left, returnSize, array);
    PostOrder(root->right, returnSize, array);
    array[(*returnSize)++] = root->val;
}

int nodenum(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return nodenum(root->left) + nodenum(root->right) + 1;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;//注意下面的判断可以有，也可以没有，但是要注意这一行代码的位置可能会导致代码出错
    if (root == NULL)
    {
        return NULL;
    }
    int size = nodenum(root);
    int* array = (int*)malloc(sizeof(int) * size);
    
    PostOrder(root, returnSize, array);
    return array;
}

//94. 二叉树的中序遍历
void InderOrder(struct TreeNode* root, int* returnSize, int* array)
{
    if (root == NULL)
    {
        return;
    }
    InderOrder(root->left, returnSize, array);
    array[(*returnSize)++] = root->val;
    InderOrder(root->right, returnSize, array);
}

int nodenum(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return nodenum(root->left) + nodenum(root->right) + 1;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL)
    {
        return NULL;
    }
    int size = nodenum(root);
    int* array = (int*)malloc(sizeof(int) * size);

    InderOrder(root, returnSize, array);
    return array;
}

//110. 平衡二叉树
int TreeHight(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lefthight = TreeHight(root->left);
    int righthight = TreeHight(root->right);

    return lefthight > righthight ? lefthight + 1 : righthight + 1;
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

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
    {
        return true;
    }
    return compare(root) && isBalanced(root->left) && isBalanced(root->right);
}

//简洁写法
int maxDepth(struct TreeNode* root) {
    return root ? 1 + fmax(maxDepth(root->left), maxDepth(root->right)) : 0;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL)
        return true;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return abs(left - right) < 2
        && isBalanced(root->left)
        && isBalanced(root->right);
}