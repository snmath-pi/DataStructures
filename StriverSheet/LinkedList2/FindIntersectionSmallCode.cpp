/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return 0;
        ListNode* d1 = headA; ListNode* d2 = headB;
        while(d1 != d2) {
            d1 = (d1 == nullptr ? headB : d1->next);
            d2 = (d2 == nullptr ? headA : d2->next);
        }
        return d1;
    }
};
