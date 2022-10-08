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
void flatenTree(Node* root){
	if(!root || (!root->left && !root->right)) return ;
	if(root->left){
		flatenTree(root->left) ;

		Node* temp = root->right ;
		root->right = root->left ;
		root->left = NULL ;
		Node* tempr = root->right ;
		while(tempr->right){
			tempr = tempr->right ;
		}
		tempr->right = temp ;


	}
	flatenTree(root->right) ;

}
void Inorder(Node*root){
	if(!root) return ;
	Inorder(root->left) ;
	cout << root->data << " " ;
	Inorder(root->right) ;
}
int main(){
	Node* root = new Node(1) ;
	root->left =new Node(2) ;
	root->right= new Node(3) ;
	root->left->left= new Node(4) ;
	flatenTree(root) ;
	Inorder(root) ;
}
