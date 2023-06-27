struct Node {
    Node* set[2];

    bool contains(int x) {
        return set[x] != nullptr;
    }
    Node* get(int x) {
        return set[x];
    }
    void put(int x, Node* node) {
        set[x] = node;
    }
};

class Trie {
    private: Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int x) {
        Node* node = root;
        for(int i=31; i>=0; i--) {
            int bit = (((x>>i)&1) == 0) ? 0 : 1;
            if(!node->contains(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int max_value(int x) {
        Node* node = root;
        int val = 0;
        for(int i=31; i>=0; i--) {
            int bit = ((x>>i) & 1);
            if(node->contains(bit ^ 1)) {
                val += (1 << i);
                node = node->get(bit^1);
            } else node = node->get(bit);
        }

        return val;
    }

    
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &x: nums) 
            trie.insert(x);
        int mx = 0;
        for(auto &x: nums) 
            mx = max(mx, trie.max_value(x));

        return mx;
    }
};
