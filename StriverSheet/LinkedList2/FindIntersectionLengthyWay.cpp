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
        int cntA = 0, cntB = 0;
        while(d1) {
            d1 = d1->next; cntA++;
        }
        while(d2 != nullptr) d2 = d2->next, cntB++;
        d1 = headA, d2 = headB;
        if(cntA >= cntB) {
            int diff = cntA - cntB;
            while(diff) {
                d1 = d1->next; diff--;
            }
            while(d1 != d2) d1 = d1->next, d2 = d2->next;
            return d1;
        }
        int diff = cntB - cntA;
        while(diff) d2 = d2->next, diff--;
        while(d1 != d2) d1 = d1->next, d2 = d2->next;
        return d2;
    }
};
