#include<iostream>
#include<stack>
#include<vector>
using namespace std;

typedef struct treenode {
	int val;
	struct treenode *left;
	struct treenode *right;
}node;

node* createnode(int val) {
	node* newnode = new node;
	newnode->val = val;
	newnode->left = nullptr; newnode->right = nullptr;
	return newnode;
}

void inorder(node *root) {
	if(root == nullptr) return;
	inorder(root->left);
	cout << root->val;
	inorder(root->right);
}

treenode* mirrortree(node* root) {
	if(!root) return root;

	node*t = root->left;
	root->left = root->right;
	root->right = t;
	if(root->left) mirrortree(root->left);
	if(root->right) mirrortree(root->right);

	return root;
}

vector<int> getInorder(node *root) {
	vector<int> res;
	node *cur = root;
	while(cur != nullptr) {
		if(cur->left == nullptr) {
			res.push_back(cur->val);
			cur=cur->right;
		} else {
			node *prev = cur->left;
			while(prev->right && prev->right != cur) prev = prev->right;
			if(prev->right == nullptr) {
				prev->right = cur;
				cur = cur->left;
			} else {
				prev->right = nullptr;
				res.push_back(cur->val);
				cur =cur->right;
			}
		}
	}
	return res;
}
int main() {
	node* tree = createnode(9);
	tree->left = createnode(3);
	tree->right = createnode(6);
	tree->left->left = createnode(1);
	tree->left->right = createnode(4);
	cout << "Iterative Inorder" << '\n';

	vector<int> res = getInorder(tree);
	for(auto &x: res) cout << x << ' ';

}
