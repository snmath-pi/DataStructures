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

void postorder(node *root) {
	if(root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->val << ' ';
}

vector<int> iterativepostorder(node *root) {
	vector<int> res;
	if(root == nullptr) return res;
	stack<node*> input;
	stack<int> output;

	input.push(root);
	while(!input.empty()) {
		node* cur = input.top();
		output.push(cur->val);
		input.pop();
		if(cur->left) input.push(cur->left);
		if(cur->right) input.push(cur->right);
	}

	while(!output.empty()) {
		int val = output.top(); output.pop();
		res.push_back(val);
	}
	return res;
}
int main() {
	node* tree = createnode(9);
	tree->left = createnode(3);
	tree->right = createnode(6);
	tree->left->left = createnode(1);
	tree->left->right = createnode(4);
	cout << "recursive postorder(NLR)" << '\n';
	postorder(tree); cout << '\n';
	cout << "Iterative postorder" << '\n';
	vector<int> res = iterativepostorder(tree);

	for(auto &x: res) cout << x << ' ';

}
