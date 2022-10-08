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
int maxTime(Node* root , map<Node* , Node*>& mpp , Node* target){
	map<Node* , bool> visited ;
	queue<Node*> q ;
	q.push(target) ;
	visited[target] = true ;
	int cnt = 0 ;
	while(!q.empty()){
		
		int fl = 0 ;
		int size = q.size() ;
		
		for(int i=0; i<size; i++){
			Node* temp = q.front() ;
			q.pop() ;
			if(temp->left && !visited[temp->left]){
				fl = 1 ;
				q.push(temp->left) ;
				visited[temp->left] = true ;
			}
			if(temp->right && !visited[temp->right]){
				fl = 1 ;
				q.push(temp->right) ;
				visited[temp->right] = true ;
			}
			if(mpp[temp] && !visited[mpp[temp]]){
				fl = 1 ;
				q.push(mpp[temp]) ;
				visited[mpp[temp]] = true ;
			}
		}
		if(fl) cnt++ ;
	}
	return cnt ;
}
Node* bfstoMapParents(Node *root , map<Node* , Node*>& mpp ,int start){
	queue<Node*> q ;
	q.push(root) ;
	Node* res ;
	while(!q.empty()){
		Node* temp = q.front() ;
		if(temp->data == start) res = temp ;
		q.pop() ;
		if(temp->left){
			mpp[temp->left] = temp ;
			q.push(temp->left) ;
		}
		if(temp->right){
			mpp[temp->right] = temp ;
			q.push(temp->right) ;
		}
	}
	return res; 

}
int TREEBURN(Node*root , int target){
	map<Node* ,Node*> mpp ;
	Node* m = bfstoMapParents(root,mpp,target) ;
	int mx = maxTime(root , mpp , m) ;
	return mx ;

}
int main(){
	Node* root = new Node(1) ;
	root->left = new Node(2) ;
	root->right = new Node(3) ;
	root->left->left= new Node(4) ;
	root->left->right = new Node(5) ;
	root->right->left = new Node(6) ;
	root->right->right = new Node(7) ;
	cout << TREEBURN(root , 3) ;


}
