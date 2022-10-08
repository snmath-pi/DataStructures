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
int  nextGreater(Node*root , int B){
	int ceil = -1 ;
	while(root){
		if(root->data == B){
			return root->data ;
		}
		if(B > root->data){
			root = root->right ;
		}
		else{
			ceil = root->data ;
			root = root->left ;
		}
	}
	return ceil ;
}
int main(){
	Node* root = new Node(5) ;
	root->left =new Node(3) ;
	root->right= new Node(4) ;
	root->left->left= new Node(1) ;
	cout << nextGreater(root , 2) ;
}
