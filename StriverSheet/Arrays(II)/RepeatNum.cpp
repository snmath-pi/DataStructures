class Solution {
public:
    int findDuplicate(vector<int>& c) {
        int a = c[0], b = c[0];
        do {
            a = c[a], b = c[c[b]];
        } while(a != b);
        a = c[0];
        while(a != b) a = c[a], b = c[b];
        return b;

    }
};
