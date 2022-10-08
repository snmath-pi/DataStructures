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
int leftheight(Node* root){
	int h = 0 ;
	while(root){
		h++ ;
		root = root->left ;
	}
	return h ;
}
int rightheight(Node* root){
	int h = 0 ;
	while(root){
		h++ ;
		root = root->right ;
	}
	return h;
}
int CountNodesOfCompleteTree(Node * root){
	if(!root) return 0 ;
	int lh = leftheight(root);
	int rh = rightheight(root) ;
	if(lh == rh) return (1<<lh ) - 1 ;
	return 1 + CountNodesOfCompleteTree(root->left) + CountNodesOfCompleteTree(root->right) ;
}
int main(){
	Node* root = new Node(1) ;
	root->left = new Node(2) ;
	root->right = new Node(3) ;
	root->left->left= new Node(4) ;
	root->left->right = new Node(5) ;
	root->right->left = new Node(6) ;
	
	cout << CountNodesOfCompleteTree(root ) ;


}
