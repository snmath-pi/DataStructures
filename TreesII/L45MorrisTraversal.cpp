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
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* node = root;
        while(node) {
            if(node->left == nullptr) {
                inorder.push_back(node->val);
                node = node->right;
            } else {
                TreeNode* lastRight = node->left;
                while(lastRight->right && lastRight->right != node) {
                    lastRight = lastRight->right;
                }
                if(lastRight->right == nullptr) {
                    lastRight->right = node;
                    node = node->left;
                } else {
                    lastRight->right = nullptr;
                    inorder.push_back(node->val);
                    node = node->right;
                }

            }
        }
        return inorder;
    }
};
