#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
	int val;
	struct ListNode* next;
};

//struct ListNode* reverse(struct ListNode* head)
//{
//	struct ListNode* pre = NULL;
//	struct ListNode* next = head->next;
//	while (head)
//	{
//		head->next = pre;
//		pre = head;
//		head = next;
//		if (next != NULL)
//		{
//			next = head->next;
//		}
//	}
//	return pre;
//}

//2. 两数相加
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* tmp1 = l1;
    struct ListNode* tmp2 = l2;

    //创建新的链表头
    struct ListNode* head = NULL, * tail = NULL;
    int capaticy = 0;
    while (tmp1 || tmp2)
    {
        int n1 = tmp1 ? tmp1->val : 0;
        int n2 = tmp2 ? tmp2->val : 0;
        capaticy = capaticy + n1 + n2;
        if (head == NULL)
        {
            head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
            tail->val = capaticy % 10;
            tail->next = NULL;
        }
        else
        {
            tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            tail->next->val = capaticy % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        capaticy /= 10;
        if (tmp1)
        {
            tmp1 = tmp1->next;
        }
        if (tmp2)
        {
            tmp2 = tmp2->next;
        }
    }
    if (capaticy != 0)
    {
        tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        tail->next->val = capaticy;
        tail->next->next = NULL;
    }
    return head;
}

//3. 无重复字符的最长子串
int lengthOfLongestSubstring(char* s)
{
    char* cur = s, * head = s;
    int max = 0;
    while (*cur)
    {
        for (char* p = head; p < cur; p++)
        {
            if (*p == *cur)
            {
                head = p + 1;
                break;
            }
        }
        max = cur - head + 1 > max ? cur - head + 1 : max;
        cur++;
    }
    return max;
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
	node1->val = 8;
	node2->val = 9;
	node3->val = 8;
	node4->val = 5;

    node5->val = 2;
    node6->val = 4;
    node7->val = 9;


	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

    node5->next = node6;
    node6->next = node7;
    node7->next = NULL;

	//struct ListNode* tmp = reverse(node1);
    struct ListNode* tmp = addTwoNumbers(node1, node5);

    char ch[] = "abcabcdefbb";
    int ret = lengthOfLongestSubstring(ch);
    printf("%d\n", ret);
	return 0;
}