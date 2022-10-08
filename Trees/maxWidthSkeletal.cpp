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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0 ;
        unsigned long long ans = 0 ;
        queue<pair<TreeNode* ,unsigned long long >> q;
        q.push({root , 0}) ;
        while(!q.empty()){
            unsigned long long sz = q.size() ;
            unsigned long long cnt = q.front().second ;
            unsigned long long first , second ;
            for(int i=0;i<sz;i++){
                unsigned long long curr_id = q.front().second - cnt ;
                TreeNode* node = q.front().first ;
                if(i == 0) first = curr_id ;
                if(i==sz-1) second = curr_id ;
                if(node->left) q.push({node->left , 2*i +1}) ;
                if(node->right) q.push({node->right , 2*i +2}) ;
            }
            ans = max(ans , second -first + 1);
        }
        return ans ;
        
    }
};
