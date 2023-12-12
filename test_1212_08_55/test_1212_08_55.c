#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};


//BM16 删除有序链表中重复的元素 - II
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    newhead->next = head;
    struct ListNode* cur = newhead;
    while (cur->next != NULL && cur->next->next != NULL)
    {
        if (cur->next->val == cur->next->next->val)
        {
            int tmp = cur->next->val;
            while (cur->next != NULL && cur->next->val == tmp)
            {
                cur->next = cur->next->next;
            }
        }
        else
        {
            cur = cur->next;
        }
    }

    return newhead->next;
}


int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	node1->val = 1;
	node2->val = 2;
	node3->val = 2;
	node4->val = 2;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	struct ListNode* tmp = deleteDuplicates(node1);
	return 0;
}

//BM23 二叉树的前序遍历
struct TreeNode 
{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

int TreeNodeNumber(struct TreeNode* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return TreeNodeNumber(root->left) + TreeNodeNumber(root->right) + 1;
}
void PreOrder(int* arr, int* returnSize, struct TreeNode* root)
{
    if (root == NULL)
    {
        return;
    }
    arr[(*returnSize)++] = root->val;
    PreOrder(arr, returnSize, root->left);
    PreOrder(arr, returnSize, root->right);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    if (root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int n = TreeNodeNumber(root);
    int* arr = (int*)malloc(sizeof(int) * n);
    PreOrder(arr, returnSize, root);
    return arr;
}