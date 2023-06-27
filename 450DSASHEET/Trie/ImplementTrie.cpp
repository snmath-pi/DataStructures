#include<bits/stdc++.h>
using namespace std;


struct Node {
	Node* links[26];
	bool ok = false;

	bool contains(char c) {
		return links[c-'a'] != nullptr;
	}
	void put(char c, Node* node) {
		links[c-'a'] = node;
	}
	Node *get(char c) {
		return links[c-'a'];
	}
	void set() {ok = true; return;}
	bool chk() {return ok;}
};
class Trie {
private: Node* root;
public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node* node = root;
		for(int i=0; i<word.length(); i++) {
			if(!node->contains(word[i])) node->put(word[i], new Node());
			node = node->get(word[i]); 
		}
		node->set();
	}

	bool search(string word) {
		Node* node = root;
		for(int i=0; i<word.length(); i++) {
			if(!node->contains(word[i])) return false;
			node = node->get(word[i]);
		}
		return node->chk();
	}
	bool startWith(string prefix) {
		Node* node = root;
		for(int i=0; i<prefix.length(); i++) {
			if(!node->contains(prefix[i])) return false;
			node = node->get(prefix[i]);
		}
		return true;
	}
};

int main()
{
	int n = 5;
	vector<int>type = {1, 1, 2, 3, 2};
	vector<string>value = {"hello", "help", "help", "hel", "hel"};
	Trie trie;
	for (int i = 0; i < n; i++) {
		if (type[i] == 1) {
			trie.insert(value[i]);
		}
		else if (type[i] == 2) {
			if (trie.search(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
		else {
			if (trie.startWith(value[i])) {
				cout << "true" << "\n";
			}
			else {
				cout << "false" << "\n";
			}
		}
	}
}
