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
string Serialize(Node* root){
	if(!root) return "" ;
	string s = " " ;

	queue<Node*> q ;
	q.push(root) ;
	while(!q.empty()){
		Node* node = q.front() ;
		q.pop() ;
		if(node == NULL){
			s.append("#,") ;
		}
		else{
			s.append(to_string(node->data)+',') ;
		}
		if(node!=NULL){
			q.push(node->left) ;
			q.push(node->right) ;
		}	
	}
	return s ;
}
Node* deserialize(string in){
	if (in.size() == 0) return NULL ;
	stringstream s(in) ;
	string str ;
	getline(s,str,',') ;
	Node* root = new Node(stoi(str)) ;
	queue<Node*> q; 
	q.push(root) ;
	while(!q.empty()){
		Node* node = q.front() ;
		q.pop() ;
		getline(s,str,',') ;
		if(str == "#"){
			node->left =NULL ;
		}
		else{
			Node* l = new Node(stoi(str)) ;
			node->left = l ;
			q.push(l) ;
		}
		getline(s,str,',') ;
		if(str == "#"){
			node->right = NULL ;
		}
		else{
			Node* r = new Node(stoi(str)) ;
			node->right = r ;
			q.push(r) ;
		}
	}
	return root ;
}
int main(){
	Node* root = new Node(1) ;
	root->left = new Node(2) ;
	root->right = new Node(3) ;
	root->left->left= new Node(4) ;
	// root->left->right = new Node(5) ;
	root->right->left = new Node(6) ;
	string s = Serialize(root) ;
	cout << s << "\n" ;
	cout << deserialize(s)->data ;
	


}
