#include <stdio.h>
#include <stdbool.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};
bool hasCycle(struct ListNode* head)
{
    //快慢指针
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast != NULL && slow != NULL)
    {
        if (fast->next != NULL)
        {
            fast = fast->next->next; //快指针每次2步
        }
        else
        {
            return false;
        }
        slow = slow->next; //慢指针每次1步
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