#include "queue.h"

//101. 对称二叉树
//bool isSymmetric_1(struct TreeNode* p1, struct TreeNode* p2)
//{
//    if (p1 == NULL && p2 == NULL)
//    {
//        return true;
//    }
//    if (p1 == NULL || p2 == NULL)
//    {
//        return false;
//    }
//    if (p1->val != p2->val)
//    {
//        return false;
//    }
//    return isSymmetric_1(p1->left, p2->right) && isSymmetric_1(p1->right, p2->left);
//}
//bool isSymmetric(struct TreeNode* root) {
//    return isSymmetric_1(root->left, root->right);
//}



typedef int TreeDataType;
typedef struct TreeNode
{
	TreeDataType val;
	struct TreeNode* left;
	struct TreeNode* right;
}TNode;

TNode* CreatTreeNode(TreeDataType x)
{
	TNode* node = (TNode*)malloc(sizeof(TNode));
	assert(node);

	node->val = x;
	node->left = node->right = NULL;
	return node;
}

TNode* CreatTree()
{
	TNode* node1 = CreatTreeNode(1);
	TNode* node2 = CreatTreeNode(2);
	TNode* node3 = CreatTreeNode(3);
	TNode* node4 = CreatTreeNode(4);
	TNode* node5 = CreatTreeNode(5);
	TNode* node6 = CreatTreeNode(6);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;

	return node1;
}

void BinaryTreeLevelOrder(TNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	int levelsize = 1;
	while (!QueueEmpty(&q))
	{
		while (levelsize--)
		{
			//一层一层的出数据
			TNode* front = QueueFront(&q);
			QueuePop(&q);
			printf("%d ", front->val);

			if (front->left)
			{
				QueuePush(&q, front->left);
			}
			if (front->right)
			{
				QueuePush(&q, front->right);
			}
		}
		printf("\n");
		levelsize = QueueSize(&q);
	}
	printf("\n");

	QueueDestroy(&q);
}

bool BinaryTreeComplete(TNode* root)
{
	//完全二叉树
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		TNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		TNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}


int main()
{
	TNode* Tree = CreatTree();
	BinaryTreeLevelOrder(Tree);
	printf("%d\n", BinaryTreeComplete(Tree));
	return 0;
}