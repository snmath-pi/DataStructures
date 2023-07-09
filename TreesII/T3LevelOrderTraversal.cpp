#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    

    queue<Node*> q;
    q.push(root);
    vector<vector<int>> res;
    while(!q.empty()) {
        int sz = q.size();
        vector<int> level;
        for(int i=0; i<sz; i++) {
            Node* temp = q.front(); q.pop();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            level.push_back(temp->data);
        }
        res.push_back(level);
    }
    int level = 0;
    for(auto &x: res) {
        cout << level++ << ": ";
        for(auto &y: x) {
            cout << y << ' ';
        }

        cout << '\n';
    }
}
