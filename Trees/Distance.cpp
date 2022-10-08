#include<bits/stdc++.h>
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
void ParentTrack(Node* root , unordered_map<Node*,Node*> &parent_track,Node*target){
	//STORES POINTER FROMC HILD TO PARETN
	if(!root) return ;
	queue<Node*> q ;
	q.push(root) ;
	while(!q.empty()){
		Node* node = q.front() ;
		q.pop() ;
		if(node->left){
			parent_track[node->left] = node ;
			q.push(node->left) ;
		}
		if(node->right){
			parent_track[node->right] = node ;
			q.push(node->right) ;
		}
	}

}
void Distance(Node* root , Node* target  , int k ){
	// IN ORDER TO MOVE ABOVE( FROM CHILD TO PARENT ) ITS NOT POSSIBLE IN A CLAS TREE
	// SO WE USE MAP TO STORE THE PARENT OF ALL THE CHILD NODES ***
	if(!root) return ;
	unordered_map<Node* , Node*> parent_track ;
	ParentTrack(root , parent_track , target) ;
	map<Node* , bool> visited ;// to store visited nodes so we don't revisit
	visited[root] = true ;
	queue<Node*> q ;
	q.push(root);
	int curr_level = 0 ; // to store until we reach distance k
	while(!q.empty()){
		int size= q.size() ;
		if(curr_level ++ == k) break;
		for(int i = 0; i<size; i++){
			Node* node = q.front() ;
			q.pop() ;
			if(node->left && !visited[node->left])
			{
				q.push(node->left) ;
				visited[node->left] = true ;
			}
			if(node->right && !visited[node->right]){
				q.push(node->right) ;
				visited[node->right] = true ;
			}
			if(parent_track[node] && !visited[parent_track[node]]){
				q.push(parent_track[node]) ;
				visited[parent_track[node]] = true ;
			}
		}
		vector<int> res ;
		while(!q.empty()){
			Node* node = q.front()  ; q.pop() ;
			res.push_back(node->data) ;
		}
		for(auto x:res){
			cout << x << " " ;
		}

	}
}
int main(){
	Node* n  = new Node(1) ;
	n->right = new Node(2) ;
	n->left = new Node(3) ;
	n->left->left = new Node(4) ;
	n->left->right = new Node(5) ;
	n->right->left = new Node(6) ;
	n->right->right = new Node(7) ;
	Distance(n , n->left , 2) ;
	
}
