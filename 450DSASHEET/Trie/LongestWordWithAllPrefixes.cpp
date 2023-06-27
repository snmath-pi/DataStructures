struct Node {
    Node* links[26];
    bool flag = false;

    bool contains(char c) {
        return links[c-'a'];
    }
    Node* get(char c) {
        return links[c-'a'];
    }
    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    } 
    bool isEnd() {
        return flag;
    }
};
class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    public: void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->contains(word[i])) node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    public: bool chkprefix(string word) {
        bool res = true;
        Node* node = root;
        for(int i=0; i<word.length(); i++) {
            if(node->contains(word[i])) {
                node = node->get(word[i]);
                res &= node->isEnd();
            }
            else 
                return false;
        }

        return res;
    }


};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        for(auto &word: words) 
            trie.insert(word);
        string mx = "";
        for(auto &x: words) {
            if(trie.chkprefix(x)) {
                if(x.length() > mx.length()) 
                    mx = x;
                else if(x.length() == mx.length() && x < mx) 
                    mx = x;
            }
        }

        return mx;
    }
};
