#include <stdio.h>
#include <stdlib.h>

//面试题 02.05. 链表求和
struct ListNode 
{
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
    tmp->next = NULL;
    struct ListNode* cur = tmp;
    int flag = 0;
    while (l1 || l2)
    {
        int num_l1 = l1 == 0 ? 0 : l1->val;
        int num_l2 = l2 == 0 ? 0 : l2->val;

        int sum = num_l1 + num_l2 + flag;
        cur->next = malloc(sizeof(struct ListNode));
        cur->next->val = sum % 10;
        cur = cur->next;
        cur->next = NULL;
        flag = sum / 10;

        if (l1)
        {
            l1 = l1->next;
        }
        if (l2)
        {
            l2 = l2->next;
        }
    }
    if (flag > 0)
    {
        cur->next = malloc(sizeof(struct ListNode));
        cur->next->val = flag;
        cur->next->next = NULL;
    }
    return tmp->next;
}

//1614. 括号的最大嵌套深度
int maxDepth(char* s)
{
    int depth = 0;
    int count = 0;
    while (*s)
    {
        if (count > depth)
        {
            depth = count;
        }
        if (*s == '(')
        {
            count++;
        }
        else if (*s == ')')
        {
            count--;
        }
        s++;
    }
    return depth;
}

int main()
{
    char ch[] = "(1) + ((2)) + (((3)))";
    printf("%d\n", maxDepth(ch));
    return 0;
}