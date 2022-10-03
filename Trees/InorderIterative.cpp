#include<bits/stdc++.h>
using namespace std ;
class TreeNode{
public:
	int data ;
	TreeNode* left ;
	TreeNode* right ;
	TreeNode(int val){
		this->data = val ;
		left = right = NULL ;
	}
};

void Inorder(TreeNode* root){
	stack<TreeNode*> s ;
	
	TreeNode* node = root ;
	while(node != NULL || !s.empty()){
		while(node != NULL){
			s.push(node) ;
			node = node->left ;

		}
		node = s.top() ;
		s.pop() ;

		cout << node->data << " " ;

		node = node->right ;
	}
}
int main(){
	struct TreeNode* root = new TreeNode(1) ;
	root->left = new TreeNode(2) ;
	root->right = new TreeNode(3) ;
	root->left->left = new TreeNode(4) ;
	root->left->right = new TreeNode(5) ;
	Inorder(root) ;
	return 0 ;
}






















// class Solution {
// public:
//     vector<int> inOrder(Node* root)
//     {
//         //code here
//         Node* node = root ;
//         stack<Node*> s  ;
//         vector<int> v ;
//         while(true){
//             if(node != NULL){
//                 s.push(node) ;
//                 node = node->left ;
//             }
//             else{
//                 if(s.empty() ) break ;
//                 node = s.top() ;
//                 v.push_back(node->data) ;
//                 s.pop() ;
//                 node = node->right ;
                
                
                
                
//             }
//         }
//         return v ;
//     }
// };
