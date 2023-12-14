#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node* next;

    Node(int d, Node* x) {
        data = d;
        next = x;
    }

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

Node* convertAtoLL(vector<int> &a) {
    Node* head = new Node(a[0]);
    Node* mover = head;
    for(int i=1; i<a.size(); i++) {
        Node* temp = new Node(a[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

}

void printLL(Node* temp) {
    for(; temp != nullptr; temp=temp->next) {
        cout << temp->data << ' ';
    }

    cout << '\n';
}

int LengthLL(Node* temp) {
    int cnt = 0;
    for(; temp != nullptr; temp=temp->next) {
        cnt++;

    }
    return cnt;
}

bool checkifPresent(Node* head, int val) {
    for(; head != nullptr; head = head->next) {
        if(head->data == val) return true;
    }
    return false;
}
int main() {
    vector<int> a = {0, 1, 2, 3};
    Node* head = convertAtoLL(a);
    printLL(head);
    cout << LengthLL(head) << '\n';


    cout << checkifPresent(head, 4 ) << '\n';
}
