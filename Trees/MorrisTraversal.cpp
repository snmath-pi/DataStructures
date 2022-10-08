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
void MorrisInorder(Node*root){
	vector<int> Inorder ;
	if(!root) return  ;
	Node* curr = root ;
	while(curr != NULL){
		if(curr->left == NULL){
			Inorder.push_back(curr->data) ;
			curr = curr->right ;
		}
		else{
			Node* prev = curr->left ;
			while(prev->right && prev->right != curr){
				prev = prev->right ;
			}
			if(prev->right ==NULL){
				prev->right =curr 	;
				curr = curr->left; 
			}
			else{
				prev->right = NULL ;
				Inorder.push_back(curr->data) ;
				curr = curr->right ;

			}
		}


	}
	for(auto x:Inorder){
		cout << x << " " ;
	}
}
int main(){
	Node* root = new Node(1) ;
	root->left =new Node(2) ;
	root->right= new Node(3) ;
	root->left->left= new Node(4) ;
	MorrisInorder(root) ;
}
