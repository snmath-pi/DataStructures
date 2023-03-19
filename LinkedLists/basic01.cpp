#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    string data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* first = NULL;
    Node* second = NULL;

    head = new Node();
    first = new Node();
    second = new Node();

    head->data = "saksham";
    head->next = first;

    first->data = "negi";
    first->next = second;

    second->data = "ryuga";
    second->next = NULL;

    while(head) {
        cout << head->data <<  "\n";
        head = head->next;
    }
}
