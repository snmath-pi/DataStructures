#include<iostream>
using namespace std ;
class Node{
public:
	int data ;
	Node* left ;
	Node* right ;
	

};
Node*newNode(int data){
	Node* new_node = new Node() ;
	new_node->data = data ;
	new_node->left = new_node->right = NULL ;
	return new_node ;
}
void Print_Inorder_Traversal(Node* node){
	if(node == NULL){
		return ;
	}
	Print_Inorder_Traversal(node->left) ;
	cout << node->data << " " ;
	Print_Inorder_Traversal(node->right) ;
}

int main(){
	Node* node = newNode(1) ;
	node->left = newNode(2) ;
	node->right=  newNode(3) ;
	Print_Inorder_Traversal(node);


	return 0 ;
}
