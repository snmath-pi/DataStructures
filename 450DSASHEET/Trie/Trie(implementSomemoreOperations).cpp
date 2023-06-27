#include<bits/stdc++.h>
using namespace std;


struct Node {
	Node* links[26];
	int cnt = 0, ew = 0;

	bool contains(char c) {
		return links[c-'a'] != nullptr;
	}
	void put(char c, Node* node) {
		links[c-'a'] = node;
	}
	Node *get(char c) {
		return links[c-'a'];
	}
	void set() {cnt++;}
	void set2() {ew++;}
	void deset() {cnt--;}
	void deset2() {ew--;}
	int getcnt() {return cnt;}
	int getew() {return ew;}

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
			node->set();
		}
		node->set2();
	}

	int cntequalto(string word) {
		Node* node = root;
		for(int i=0; i<word.length(); i++) {
			if(node->contains(word[i])) node = node->get(word[i]);
			else return 0;
		}
		return node->getew();
	}
	int startWith(string prefix) {
		Node* node = root;
		for(int i=0; i<prefix.length(); i++) {
			if(node->contains(prefix[i])) node = node->get(prefix[i]);
			else return 0;
		}
		return node->getcnt();
	}
	void erase(string word) {
		Node* node = root;
		for(int i=0; i<word.length(); i++) {
			if(node->contains(word[i])) {
				node = node->get(word[i]);
				node->deset();
			} else return;
		}
		node->deset2();
	}
};

int main()
{
	Trie T;
  T.insert("apple");
  T.insert("apple");
  T.insert("apps");
  T.insert("apps");
  string word1 = "apps";
  cout<<"Count Words Equal to "<< word1<<" "<<T.cntequalto(word1)<<endl;
  string word2 = "abc";
  cout<<"Count Words Equal to "<< word2<<" "<<T.cntequalto(word2)<<endl;
  string word3 = "ap";
  cout<<"Count Words Starting With "<<word3<<" "<<T.startWith(word3)
  <<endl;
  string word4 = "appl";
  cout<<"Count Words Starting With "<< word4<<" "<<T.startWith(word4)
  <<endl;
  T.erase(word1);
  cout<<"Count Words equal to "<< word1<<" "<<T.cntequalto(word1)<<endl;
  return 0;
}
