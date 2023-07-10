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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        TreeNode* node = root;
        while(node) {
            if(node->left == nullptr) {
                k--;
                if(k == 0) {
                    ans = node->val;
                }
                node = node->right;
            } else {
                TreeNode* temp = node->left;
                while(temp->right != nullptr && temp->right != node) temp = temp->right;
                if(temp->right == nullptr) {
                    temp->right = node;
                    node = node->left;
                } else {
                    temp->right = nullptr;
                    k--;
                    if(k == 0) {
                        ans = node->val;
                    }
                    node = node->right;
                }
            }
        }
        return ans;
    }
    
};
