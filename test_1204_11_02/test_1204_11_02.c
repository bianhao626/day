//145. �������ĺ������
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
    *returnSize = 0;//ע��������жϿ����У�Ҳ����û�У�����Ҫע����һ�д����λ�ÿ��ܻᵼ�´������
    if (root == NULL)
    {
        return NULL;
    }
    int size = nodenum(root);
    int* array = (int*)malloc(sizeof(int) * size);
    
    PostOrder(root, returnSize, array);
    return array;
}

//94. ���������������
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

//110. ƽ�������
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

//���д��
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