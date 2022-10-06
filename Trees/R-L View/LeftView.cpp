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
// Reverse PreOrder(root right left)( basically right side view is last element at each lvl) ;
void RightView(Node*root , int lvl , vector<int> &v) ;
vector<int> RV(Node* node){
	vector<int> res ;
	RightView(node,0,res) ;
	return res ;
}
void RightView(Node* root , int lvl , vector<int> &v){
	

	if(root == NULL) return ;
	if(v.size() == lvl) v.push_back(root->data) ;
	RightView(root->left , lvl +1 ,v) ;
	RightView(root->right , lvl+1 , v) ;
	
	
}
int main(){
	Node* root = new Node(1);
	root->left = new Node(2) ;
	root->right = new Node(3) ;
	root->left->left = new Node(4) ;
	root->left->right = new Node(5) ;
	root->left->right->left = new Node(6) ;
	root->right->right = new Node(7) ;
	vector<int> v = RV(root);
	for(auto &x:v){ cout << x << " " ;}

}
