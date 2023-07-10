/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        int res = root->val;
        if(res < p->val&& res < q->val) return lowestCommonAncestor(root->right, p, q);
        if(res > p->val && res > q->val) return lowestCommonAncestor(root->left, p,q);
        return root;
        
    }
};
