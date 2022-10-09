#include<bits/stdc++.h>
using namespace std ;
class Node{
public:
	int data ;
	Node* left ;
	Node* right ;
	Node(int val){
		this->data = val ;
		left = right = NULL ;
	}
};
int KthSmallestInBst(Node* root , int k){
	int ans = -1 ;
	Node* curr = root; 
	while(curr){
		if(curr->left == NULL){
			if(--k==0){
				ans = curr->data ;
			}
			curr = curr->right ;

		}
		else{
			Node* rightMost = curr->left ;
			if(rightMost->right && rightMost->right != curr ){
				rightMost = rightMost->right ;
			}
			if(rightMost->right == NULL){
				rightMost->right = curr ;
				curr = curr->left ;
			}
			else{
				rightMost->right = NULL ;
				if(--k == 0){
					ans = curr->data ;
				}
				curr = curr->right ;
			}
		}
	}
	return ans ;
}
int main(){
	Node* root = new Node(11) ;
	root->left =new Node(3) ;
	root->right= new Node(16) ;
	root->left->left= new Node(1) ;
	cout << KthSmallestInBst(root, 4) ;
	
	
}
