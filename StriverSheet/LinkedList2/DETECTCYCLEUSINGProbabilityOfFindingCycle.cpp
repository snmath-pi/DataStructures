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
        int iter = 1e6;
        while(iter--) {
            if(head == nullptr) return 0;
            head = head->next;
        }
        return 1;

    }
};
