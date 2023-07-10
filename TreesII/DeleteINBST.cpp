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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        if(!root->left && !root->right && root->val == key) return nullptr;
        TreeNode* node = root;
        TreeNode* prev = root;
        if(root->val == key) {
            TreeNode* node = root;

            if(node->right && node->left) {
                TreeNode* temp  =node->right;
                while(temp->left) temp = temp->left;
                temp->left = node->left;
                root = node->right;
                delete(node);
                return root;
            }
            else if(node->right) {
                root = node->right;
                delete(node);
                return root;
            }
            else if(node->left) {
                root = node->left;
                delete(node);
                return root;
            }
            
        }
        while(node) {
            if(node->val == key) {
                if(node->left && node->right) {
                    if(prev->val < key) {
                        TreeNode* temp = node->right;
                        while(temp->left) temp = temp->left;
                        temp->left = node->left;
                        prev->right = node->right;
                        delete(node);

                        
                    } else {
                        TreeNode* temp = node->right;
                        while(temp->left) temp = temp->left;
                        temp->left = node->left;
                        prev->left = node->right;
                        delete(node);
                    }
                } else if (node->left) {
                    if(prev->val > key) {
                       prev->left = node->left;
                       delete(node);
                        
                    } else {
                       prev->right = node->left;
                       delete(node);
                    }
                } else if(node->right) {
                    if(prev->val > key) {
                       prev->left = node->right;
                       delete(node);
                        
                    } else {
                       prev->right = node->right;
                       delete(node);
                    }
                } else {
                    if(prev->val > key) {
                        delete(node);
                        prev->left = nullptr;
                        
                    } else {
                        delete(node);
                        prev->right = nullptr;
                    }
                }
                break;
            } else if(node->val < key) {
                prev = node;
                node = node->right;
            } else {
                prev = node;
                node = node->left;
            }
        }
        return root;
    }
};
