/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // step 1.
        Node* iter = head; Node* front = head;
        while(iter) {
            front = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        // step2.
        iter = head;
        while(iter) {
            if(iter->random != nullptr) {
                iter->next->random = iter->random->next;
            } 
            iter = iter->next->next;
        }
        // step3.
        iter = head;
        // pseudohead;
        Node* ans = new Node(0);
        Node* dummy = ans;
        while(iter != nullptr) {
            front = iter->next->next;
            dummy->next = iter->next;
            iter->next = front;
            dummy = dummy->next;
            iter = front;
        }

        return ans->next;

    }
};
