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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        TreeNode* node = root;
        while(node) {
            if(node->left == nullptr) {
                preorder.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* lastRight = node->left;
                while(lastRight->right && lastRight->right != node) {
                    lastRight = lastRight->right;
                }
                if(lastRight->right == nullptr) {
                    lastRight->right = node;
                    preorder.push_back(node->val);
                    node=node->left;
                } else {
                    lastRight->right = nullptr;
                    node=node->right;
                }
            }
        }
        return preorder;
    }
};
