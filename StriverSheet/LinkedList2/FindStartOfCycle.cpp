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
    bool chkcycle(ListNode* head) {
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare && hare->next && hare->next->next) {
            tortoise = tortoise->next;
            hare = hare->next->next;
            if(tortoise == hare) return true;
        }
        return false;
    }
    ListNode *detectCycle(ListNode *head) {
        if(!chkcycle(head)) return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while(slow != fast);
        slow = head;
        int pos = 0;
        while(slow != fast) {
            slow = slow->next; fast = fast->next;
            pos++;
        }
        return slow;
    }
};
