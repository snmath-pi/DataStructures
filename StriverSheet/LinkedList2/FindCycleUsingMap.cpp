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
        if(head == nullptr) return 0;
        map<ListNode *, int> mp;
        while(head) {
            if(mp.find(head) != mp.end()) {
                return 1;
            }
            mp[head]++;
            head = head->next;
        }
        return 0;
    }
};
