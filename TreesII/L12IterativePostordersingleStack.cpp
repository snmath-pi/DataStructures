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

    stack<Node*> st;
    Node* node = root;
    vector<int> res;
    while(!st.empty() || node != nullptr) {
        if(node) {
            st.push(node); 
            node = node->left;
        }  else {
            Node* temp = st.top()->right;
            if(!temp) {
                temp = st.top();
                res.push_back(temp->data);
                st.pop();
                while(!st.empty() && temp == st.top()->right) {
                    temp = st.top(); st.pop();
                    res.push_back(temp->data);
                }
            } else node = temp;
        }     
    }
    for(auto &x: res) cout << x << ' ';

    
}
