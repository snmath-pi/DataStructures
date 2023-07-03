/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reversal(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* nx = nullptr;
        while(head) {
            nx = head->next;
            head->next = pre;
            pre = head;
            head = nx;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || head->next == nullptr) return 1;
        ListNode* tortoise = head;
        ListNode* hare = head;
        while(hare->next && hare->next->next) {
            hare = hare->next->next;
            tortoise = tortoise->next;
        }
        tortoise->next = reversal(tortoise->next);
        tortoise = tortoise->next;
        while(tortoise) {
            if(head->val != tortoise->val) return false;
            head = head->next;
            tortoise = tortoise->next;
        }
        return true;
    }
};
