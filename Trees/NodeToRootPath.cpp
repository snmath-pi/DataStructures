#include<iostream>
#include<vector>
#include<utility>
#include<stack>
#include<cmath>
#include<array>
using namespace std ;
class Node{
public:
	int data ;
	Node* left ;
	Node* right ;
	Node(int v){
		this->data = v ;
		left =right = NULL ;
	}
};
bool ispath(Node* root , vector<int> &v , int x){
	if(!root) return NULL ;
	v.push_back(root->data) ;
	if(root->data == x) return true ;
	if(ispath(root->left , v,x) || ispath(root->right , v, x)) return true ;
	v.pop_back() ;
	return false ;
}
void PrintPath(Node*root , int x){
	vector<int> ans ;
	if(ispath(root , ans , x )){
		for(int i=0; i<ans.size(); i++){
			cout << ans[i] << " " ;
		}
	}
	else cout << "NO path found " ;
}
int main()
{
    // binary tree formation
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
         
    int x = 5;
    PrintPath(root, x);
    return 0;
}
