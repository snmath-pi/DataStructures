/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *deleteLast(Node *list){
    // Write your code here
    if(!list || !list->next) return nullptr;
    Node* iq = list;
    Node* temp = list;
    for(; temp->next->next!=nullptr; temp = temp->next);

    Node* toji = temp->next;
    delete(toji);
    temp->next = nullptr;
    return iq;
}
