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
public:
    TreeNode* dfs(vector<int> &a, int &id, int bound) {
        if(id == a.size() || a[id] > bound) return nullptr;
        TreeNode* node = new TreeNode(a[id++]);
        node->left = dfs(a, id, node->val);
        node->right = dfs(a, id, bound);
        return node;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = 0;
        return dfs(preorder, n, INT_MAX);
    }
};
