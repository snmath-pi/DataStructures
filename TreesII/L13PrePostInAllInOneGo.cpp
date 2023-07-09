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

void inorder(Node* root) {
    if(root->left) inorder(root->left);
    cout << root->data << ' ';
    if(root->right) inorder(root->right);
}
void preorder(Node* root) {
    cout << root->data << ' ';
    if(root->left) preorder(root->left);
    if(root->right) preorder(root->right);
}

void postorder(Node* root) {
    if(root->left) postorder(root->left);
    if(root->right) postorder(root->right);
    cout << root->data << ' ';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);

    stack<pair<Node*, int>> st;
    Node* node = root;
    vector<int> preorder, inorder, postorder;
    st.push({node, 1});
    while(!st.empty()) {
        Node* temp = st.top().first;
        int num = st.top().second;    
        st.pop();
        if(num == 1) {
            preorder.push_back(temp->data);

            st.push({temp, 2});
            if(temp->left) {
                st.push({temp->left, 1});
            }
        } else if(num == 2) {
            inorder.push_back(temp->data);
            st.push({temp, 3});
            if(temp->right) st.push({temp->right, 1});
        } else {
            postorder.push_back(temp->data);
        }
    }
    for(auto &x: inorder) cout << x << ' ';
    cout << '\n';
    for(auto &x: preorder) cout << x << ' ';
    cout << '\n';
    for(auto &x: postorder) cout << x << ' ';

    
}
