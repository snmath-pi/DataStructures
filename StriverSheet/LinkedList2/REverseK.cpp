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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || k == 1) return head;
        int cnt = 0;
        ListNode* cur = head;
        while(cur) cur = cur->next, cnt++;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        cur = dummy; ListNode* nx = dummy; ListNode* pre = dummy;
        while(cnt >= k) {
            cur = pre->next;
            nx = cur->next;
            for(int i=1; i<k; i++) {
                cur->next = nx->next;
                nx->next = pre->next;
                pre->next = nx;
                nx = cur->next;
            }
            pre = cur;
            cnt -= k;
        }
        return dummy->next;
        
    }
};
