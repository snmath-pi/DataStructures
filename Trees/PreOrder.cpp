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
void Print_PreOrder_Traversal(Node* node){
	if(node == NULL){
		return ;
	}
	cout << node->data << " " ;
	Print_PreOrder_Traversal(node->left) ;
	Print_PreOrder_Traversal(node->right) ;

}

int main(){
	Node* node = newNode(1) ;
	node->left = newNode(2) ;
	node->right=  newNode(3) ;
	node->left->left = newNode(5) ;
	node->right->left = newNode(6) ;
	node->right->right = newNode(4) ;
	Print_PreOrder_Traversal(node);


	return 0 ;
}
