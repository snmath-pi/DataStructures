#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int close = -1;
    while(root != nullptr) {
        if(root->val == X) return X;
        else if(root->val > X) root = root->left;
        else {
            if(close == -1) close = root->val;
            else close = max(close, root->val);
            root = root->right;
        }
    }
    return close;
}
