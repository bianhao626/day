#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};
bool hasCycle(struct ListNode* head)
{
    //����ָ��
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast != NULL && slow != NULL)
    {
        if (fast->next != NULL)
        {
            fast = fast->next->next; //��ָ��ÿ��2��
        }
        else
        {
            return false;
        }
        slow = slow->next; //��ָ��ÿ��1��
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    return 0;
}