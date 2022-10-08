#include<iostream>
using namespace std; 
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
void InorderTrav(Node* root){
	if(!root) return ;
	InorderTrav(root->left) ;
	cout << root->data << " " ;
	InorderTrav(root->right) ;
}
void ConvertTree(Node* root){
	if(!root) return ;
	int cnt = 0 ;
	if(root->left) cnt += root->left->data;
	if(root->right) cnt += root->right->data ;
	if(cnt >= root->data) root->data = cnt ;
	else{
		if(root->left) root->left->data = root->data ;
		if(root->right) root->left->data = root->data ;
	}
	ConvertTree(root->left) ;
	ConvertTree(root->right) ;
	int totVal = 0 ;
	if(root->left) totVal+= root->left->data ;
	if(root->right) totVal += root->right->data ;
	if(root->left || root->right) root->data = totVal ;

}
int main(){
	Node* n  = new Node(1) ;
	n->right = new Node(2) ;
	n->left = new Node(3) ;
	n->left->left = new Node(4) ;
	n->left->right = new Node(5) ;
	n->right->left = new Node(6) ;
	n->right->right = new Node(7) ;
	ConvertTree(n) ;
	InorderTrav(n) ;
}
