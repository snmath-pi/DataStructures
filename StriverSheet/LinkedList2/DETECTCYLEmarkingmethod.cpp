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
    bool hasCycle(ListNode *head) {
        while(head) {
            if(head->val == -1e8) return 1;
            head->val = -1e8;
            head = head->next;
        }
        return 0;

    }
};
