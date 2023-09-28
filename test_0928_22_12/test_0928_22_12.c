#include <stdio.h>
struct ListNode {
	int val;
	struct ListNode* next;
};
struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2) {
    // write code here
    struct ListNode* p1 = pHead1;
    struct ListNode* p2 = pHead2;

    int l1 = 0, l2 = 0;
    while (p1) {
        l1++;
        p1 = p1->next;
    }
    while (p2) {
        l2++;
        p2 = p2->next;
    }
    int sub = l1 > l2 ? l1 - l2 : l2 - l1;
    p1 = pHead1;
    p2 = pHead2;
    if (l1 > l2) {
        while (sub--) {
            p1 = p1->next;
        }
    }
    else if (l1 < l2) {
        while (sub--) {
            p2 = p2->next;
        }
    }
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p1;
}