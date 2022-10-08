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
Node* SearchBST(Node* root , int val){
	while(root && root->data!=val){
		root = val<root->data?root->left:root->right ;
	}
	return root ;
}
int main(){
	Node* root = new Node(5) ;
	root->left =new Node(3) ;
	root->right= new Node(4) ;
	root->left->left= new Node(1) ;
	cout << SearchBST(root , 10) ;
}
