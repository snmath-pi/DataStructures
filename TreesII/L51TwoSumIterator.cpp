/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTiterator {
    private: stack<TreeNode*> st;
    public:
    bool reverse;
    BSTiterator(TreeNode* node, bool flag) {
        reverse = flag;
        pushall(node);
    }
    bool hasNext() {
        return !st.empty();
    }
    int next() {
        TreeNode* node = st.top(); st.pop();
        pushall((reverse ? (node->left) : (node->right)));
        return node->val;
    }
    private: void pushall(TreeNode* node) {
        for(;node; st.push(node), (node = (reverse ? node->right : node->left)) );
    }
};
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTiterator l(root, 0);
        BSTiterator r(root, 1);
        int i = l.next();
        int j = r.next();
        while(i < j) {
            if(i + j == k) return true;
            else if(i + j > k) j = r.next();
            else i = l.next();
        }
        return false;
    }
};
