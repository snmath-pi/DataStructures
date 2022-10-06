#include<iostream>
#include<queue>
#include<map>
#include<utility> 
#include<vector>

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
} ;
// Iterative Approach making queue
bool RECr(Node* l , Node* r){
	if(!l && !r) return true ;
	if(l && r && (l->data != r->data)) return false;
	return RECr(l->left , r->right) && RECr(l->right , r->left) ;
}
bool RecSymmetric(Node* root){
	return root == NULL || RECr(root->left , root->right) ;
}

bool ItrSymmetric(Node*root){
	if(root == NULL) return true ;
	if(!root->left && !root->right)
		return true ;
	queue<Node*> q ;
	q.push(root) ;
	q.push(root) ;
	while(!q.empty()){
		Node* leftNode = q.front() ;
		q.pop() ;
		Node* rightNode = q.front() ;
		q.pop() ;
		if(leftNode->data != rightNode->data) return false ;
		if(leftNode->left && rightNode->right){
			q.push(leftNode->left) ;
			q.push(rightNode->right) ;
		}
		else if(leftNode->left || rightNode->right) return false ;
		if(leftNode->right && rightNode->left){
			q.push(leftNode->right) ;
			q.push(rightNode->left) ;

		}
		else if(leftNode->left || rightNode->right) return false ;
	}
	return true ;

}

int main(){
	Node* root = new Node(1);
	root->left = new Node(2) ;
	root->right = new Node(3) ;
	root->left->left = new Node(4) ;
	root->left->right = new Node(5) ;
	root->left->right->left = new Node(6) ;
	root->right->right = new Node(7) ;
	cout << ((ItrSymmetric(root))?"YES":"NO" ) ;
	cout << "\n" ;
	cout << ((RecSymmetric(root))?"YES":"NO" ) ;


}
