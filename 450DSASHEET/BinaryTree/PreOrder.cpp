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

void preorder(node *root) {
	if(root == nullptr) return;
	cout << root->val << ' ';
	preorder(root->left);
	preorder(root->right);
}

vector<int> iterativepreorder(node *root) {
	vector<int> res;
	if(root == nullptr) return res;
	stack<node*> s;
	s.push(root);
	while(!s.empty()) {
		node* cur = s.top(); s.pop();
		res.push_back(cur->val);
		if(cur->right) s.push(cur->right);
		if(cur->left) s.push(cur->left);
	}

	return res;
}
int main() {
	node* tree = createnode(9);
	tree->left = createnode(3);
	tree->right = createnode(6);
	tree->left->left = createnode(1);
	tree->left->right = createnode(4);
	cout << "recursive preorder(NLR)" << '\n';
	preorder(tree); cout << '\n';
	cout << "Iterative preorder" << '\n';
	vector<int> res = iterativepreorder(tree);

	for(auto &x: res) cout << x << ' ';

}
