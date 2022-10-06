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
void BottomView(Node* root){
	vector<int> ans ;
	if(root == NULL) return;
	map<int,int> mp ;
	queue<pair<Node*,int>> q ;
	q.push({root, 0}) ;
	while(!q.empty()){
		auto x = q.front() ;
		q.pop() ;
		Node* node = x.first ;
		int lvl = x.second ;
		mp[lvl] = node->data ;
		if(node->left) q.push({node->left , lvl -1 }) ;
		if(node->right) q.push({node->right , lvl +1 }) ;


	}
	for(auto x:mp){
		ans.push_back(x.second) ;
	}
	 
	for(int i = 0 ;i<ans.size() ;i++){
		cout << ans[i] << " ";
	}

}
int main(){
	Node* root = new Node(1);
	root->left = new Node(2) ;
	root->right = new Node(3) ;
	root->left->left = new Node(5) ;
	root->left->right = new Node(6) ;
	root->right->left = new Node(7) ;
	BottomView(root) ;
}
