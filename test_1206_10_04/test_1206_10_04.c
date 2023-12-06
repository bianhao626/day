#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};




//BM11 链表相加(二)
//用例只适用于一些简单的案例，过长案例不适用
//int ListNodeSize(struct ListNode* head)
//{
//    if (head == NULL)
//    {
//        return 0;
//    }
//    int count = 1;
//    while (head->next)
//    {
//        head = head->next;
//        count++;
//    }
//    return count;
//}
//
//struct ListNode* CreatNewNode(int x)
//{
//    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//    node->val = x;
//    node->next = NULL;
//    return node;
//}
//
//struct ListNode* addInList(struct ListNode* head1, struct ListNode* head2)
//{
//    int len1 = ListNodeSize(head1);
//    int len2 = ListNodeSize(head2);
//    struct ListNode* p1 = head1;
//    struct ListNode* p2 = head2;
//    int sum1 = 0;
//    int sum2 = 0;
//    while (p1)
//    {
//        len1--;
//        sum1 += pow(10, len1) * (p1->val);
//        p1 = p1->next;
//    }
//    while (p2)
//    {
//        len2--;
//        sum2 += pow(10, len2) * (p2->val);
//        p2 = p2->next;
//    }
//    int sum = sum1 + sum2;
//    struct ListNode* newhead = (struct ListNode*)malloc(sizeof(struct ListNode));
//    newhead->next = NULL;
//    while (sum)
//    {
//        int tmp = sum % 10;
//        struct ListNode* node = CreatNewNode(tmp);
//        node->next = newhead->next;
//        newhead->next = node;
//        sum /= 10;
//    }
//    return newhead->next;
//}



struct ListNode* reverse(struct ListNode* node)
{
    struct ListNode* pre = NULL;
    struct ListNode* cur = node;
    struct ListNode* next = NULL;
    while (cur)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

struct ListNode* addInList(struct ListNode* head1, struct ListNode* head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    if (head1->next)
    {
        head1 = reverse(head1);
    }
    if (head2->next)
    {
        head2 = reverse(head2);
    }
    struct ListNode* head3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head3->next = NULL;
    struct ListNode* p1 = head1;
    struct ListNode* p2 = head2;
    int tmp = 0;
    while (p1 || p2)
    {
        int val = tmp;
        if (p1)
        {
            val += p1->val;
            p1 = p1->next;
        }
        if (p2)
        {
            val += p2->val;
            p2 = p2->next;
        }
        tmp = val / 10;
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = val % 10;
        newnode->next = head3->next;
        head3->next = newnode;
    }
    if (tmp > 0)
    {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = tmp;
        newnode->next = head3->next;
        head3->next = newnode;
    }
    return head3->next;
}

//BM12 单链表的排序
//C语言实现的方式，代码量较大
//建议C++方式实现
int ListSize(struct ListNode* node)
{
    int count = 1;
    if (node == NULL)
    {
        return 0;
    }
    while (node->next)
    {
        node = node->next;
        count++;
    }
    return count;
}

void Swap(int* p1, int* p2)
{
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void AdjustDown(int* a, int size, int parent)
{
    int child = parent * 2 + 1;
    while (child < size)
    {
        if (child + 1 < size && a[child + 1] > a[child])
        {
            child++;
        }
        if (a[child] > a[parent])
        {
            Swap(&a[child], &a[parent]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}
void HeapSort(int* a, int n)
{
    for (int i = (n - 1 - 1) / 2; i >= 0; i--)
    {
        AdjustDown(a, n, i);
    }

    int end = n - 1;
    while (end)
    {
        Swap(&a[0], &a[end]);
        AdjustDown(a, end, 0);
        end--;
    }
}

struct ListNode* sortInList(struct ListNode* head)
{
    int len = ListSize(head);
    int* arr = (int*)malloc(sizeof(int) * len);
    //升序，建大根堆
    int i = 0;
    while (head)
    {
        arr[i++] = head->val;
        head = head->next;
    }
    HeapSort(arr, len);
    struct ListNode* rethead = (struct ListNode*)malloc(sizeof(struct ListNode));
    rethead->next = NULL;
    struct ListNode* cur = rethead;
    for (int j = 0; j < len; j++)
    {
        struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val = arr[j];
        newnode->next = cur->next;
        cur->next = newnode;
        cur = newnode;
    }
    return rethead->next;
}

int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	node1->val = 9;
	node2->val = 3;
	node3->val = 7;

    node4->val = 6;
    node5->val = 3;

	node1->next = node2;
	node2->next = node3;
    node3->next = NULL;

    node4->next = node5;
    node5->next = NULL;

    struct ListNode* tmp = sortInList(node1);
	return 0;
}