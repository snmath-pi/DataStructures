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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        int length = 0;
        ListNode* iter = head;
        while(iter) iter = iter->next, length++;
        if(length == 1) return head;
        int req = k % length;
        ListNode* ans = nullptr;
        for(int i=1; i<=req; i++) {
            iter = head;
            ListNode* cur = nullptr; 
            while(iter->next) {
                cur = iter;
                iter = iter->next;
            }
            iter->next = head;
            cur->next = nullptr;
            head = iter;
        }

        return head;
    }
};
