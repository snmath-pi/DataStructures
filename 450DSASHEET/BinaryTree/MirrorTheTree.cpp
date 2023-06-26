#include<iostream>
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

int main() {
	node* tree = createnode(5);
	tree->left = createnode(3);
	tree->right = createnode(6);
	tree->left->left = createnode(2);
	tree->left->right = createnode(4);
	cout << "original\n";
	inorder(tree);
	mirrortree(tree);
	cout << '\n';
	cout << "mirriored\n";
	inorder(tree);
	return 0;
}
