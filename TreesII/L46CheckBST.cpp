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
class Solution {
private:
    bool dfs(TreeNode* node, int64_t mn, int64_t mx) {
        if(!node) return true;
        if((int64_t)node->val >= mx || (int64_t)node->val <= mn) return false;
        return dfs(node->left, mn, node->val) && dfs(node->right, node->val, mx);
    }
public:
    
    bool isValidBST(TreeNode* root) {
        return dfs(root, -1e15, 1e15);
    }
};
