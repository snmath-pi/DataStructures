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
bool CheckBST(Node* root , int a , int b){
	if(!root) return true ;
	if(root->data <= a || root->data >= b) return false ;
	return (CheckBST(root->left , a , root->data) && CheckBST(root->right , root->data,b)) ;
}
bool isValidBST(Node*root){
	return CheckBST(root , -1e9 , 1e9) ;
}
int main(){
	Node* root = new Node(11) ;
	root->left =new Node(3) ;
	root->right= new Node(16) ;
	root->left->left= new Node(199) ;
	cout << isValidBST(root) ;
	
	
}
