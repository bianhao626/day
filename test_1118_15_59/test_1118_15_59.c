#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{
    int val;
    struct ListNode *next;
};
 
//struct ListNode* reverseList(struct ListNode* head)
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    struct ListNode* n1, * n2, * n3;
//    n1 = NULL;
//    n2 = head;
//    n3 = head->next;
//
//
//    while (n2)
//    {
//        n2->next = n1;
//        n1 = n2;
//        n2 = n3;
//        if (n3 != NULL)
//        {
//            n3 = n2->next;
//        }
//    }
//    return n1;
//}

//struct ListNode* detectCycle(struct ListNode* head)
//{
//    //注意找到入口的方式
//    struct ListNode* slow = head, * fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if (slow == fast)
//        {
//            slow = head;
//            while (slow != fast)
//            {
//                slow = slow->next;
//                fast = fast->next;
//            }
//            return slow;
//        }
//    }
//    return NULL;
//}

//力扣138随机链表的复制
//struct Node 
//{
//    int val;
//    struct Node* next;
//    struct Node* random;
//};
//struct Node* copyRandomList(struct Node* head)
//{
//    if (head == NULL)
//    {
//        return NULL;
//    }
//    struct Node* cur = head;
//    while (cur)
//    {
//        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
//        newnode->val = cur->val;
//        newnode->random = NULL;
//        newnode->next = cur->next;
//        cur->next = newnode;
//        cur = newnode->next;
//    }
//
//    cur = head;
//    while (cur)
//    {
//        if (cur->random != NULL)
//        {
//            cur->next->random = cur->random->next;
//        }
//        cur = cur->next->next;
//    }
//
//    cur = head->next;
//    struct Node* pre = head, * ret = head->next;
//    while (cur->next)
//    {
//        pre->next = pre->next->next;
//        cur->next = cur->next->next;
//        pre = pre->next;
//        cur = cur->next;
//    }
//    pre->next = NULL;
//    return ret;
//}

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    struct ListNode* p1 = headA, * p2 = headB;
    int countA = 0;
    int countB = 0;

    while (p1)
    {
        countA++;
        p1 = p1->next;
    }
    while (p2)
    {
        countB++;
        p2 = p2->next;
    }

    p1 = headA;
    p2 = headB;
    if (countA > countB)
    {
        for (int i = 0; i < countA - countB; i++)
        {
            p1 = p1->next;
        }
    }
    else
    {
        for (int i = 0; i < countB - countA; i++)
        {
            p2 = p2->next;
        }
    }

    while (p1)
    {
        if (p1 == p2)
        {
            return p2;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return NULL;
}

int main()
{
	struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* node7 = (struct ListNode*)malloc(sizeof(struct ListNode));

    node1->val = 4;
    node2->val = 1;
    node3->val = 8;
    node4->val = 4;
    node5->val = 5;
    node6->val = 5;
    node7->val = 6;


	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;
    node6->next = node7;
    node7->next = node2;

    struct ListNode* tmp = getIntersectionNode(node1, node6);
	return 0;
}



//牛客网OR 链表的回文结构
//错误代码，思路正确但是出现问题
//#include <cstddef>
//class PalindromeList {
//public:
//    bool chkPalindrome(ListNode* A)
//    {
//        struct ListNode* slow = A, * fast = A, * pre = NULL;
//        while (fast->next)
//        {
//            pre = slow;
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//
//        pre->next = NULL;
//        pre = slow;
//        pre->next = NULL;
//        struct ListNode* next;
//        if (slow->next)
//        {
//            slow = slow->next;
//            next = slow->next;
//        }
//        while (slow)
//        {
//            slow->next = pre;
//            pre = slow;
//            slow = next;
//            if (next)
//            {
//                next = slow->next;
//            }
//        }
//
//        fast = A;
//        while (fast)
//        {
//            if (fast->val == pre->val)
//            {
//                fast = fast->next;
//                pre = pre->next;
//            }
//            else
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//};

#include <cstddef>
#include <cstdlib>
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A)
    {
        struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
        n->next = A;

        struct ListNode* slow = n;
        struct ListNode* fast = n;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        struct ListNode* cur = slow->next;
        struct ListNode* pre = slow;
        struct ListNode* next = cur->next;
        slow->next = NULL;

        while (1)
        {
            cur->next = pre;
            pre = cur;
            if (next == NULL)
            {
                break;
            }
            cur = next;
            next = cur->next;
        }

        struct ListNode* head = A;
        struct ListNode* tail = cur;
        while (tail != slow)
        {
            if (head->val != tail->val)
            {
                return false;
            }
            head = head->next;
            tail = tail->next;
        }
        return true;
    }
};
