#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int close = -1;
    while(node != nullptr) {
        if(node->data == x) return x;
        else if(node->data < x) node = node->right;
        else {
            if(close == -1) close = node->data;
            else close = min(close, node->data);
            node = node->left;
        }
    }
    return close;
}
