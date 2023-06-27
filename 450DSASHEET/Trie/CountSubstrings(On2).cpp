#include<bits/stdc++.h>
using namespace std;

class Trie {
public:
	bool flag;
	Trie *child[26];

	Trie() {
		flag = 0;
		for(int i=0; i < 26; i++) 
			child[i] = 0;

	}
public: void put(char c, Trie* node) {
	child[c-'a'] = node;
}
public: Trie* get(char c) {
	return child[c-'a'];
}
public: void set() {flag = 1;}
};

int countDistinctSubstring(string s) {
	Trie *root = new Trie();

	int cnt = 0;
	for(int i=0; i<s.size(); i++) {
		Trie* node = root;
		for(int j=i; j<s.size(); j++) {
			if(node->child[s[j] - 'a'] == nullptr) {
				node->put(s[j], new Trie());
				node->set();
				cnt++;
			}
			node = node->get(s[j]);
		}
	}


	return cnt;
}

int main() {
	string s = "abab";
	cout << countDistinctSubstring(s);
}
