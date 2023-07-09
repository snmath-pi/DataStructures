class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set s(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> usedonLevel;
        usedonLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>> res;
        while(!q.empty()) {
            vector<string> v = q.front();
            q.pop();
            if(v.size() > level) {
                level++;
                for(auto &it: usedonLevel) {
                    s.erase(it);
                }
                usedonLevel.clear();
            }

            string word = v.back();
            if(word == endWord) {
                if(res.size() == 0) {
                    res.push_back(v);
                } else if(res[0].size() == v.size()) {
                    res.push_back(v);
                }
            }
            for(int i=0; i<word.size(); i++) {
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++) {
                    word[i] = c;
                    if(s.count(word)) {
                        v.push_back(word);
                        q.push(v);
                        usedonLevel.push_back(word);
                        v.pop_back();
                    }
                }
                word[i] = original;
            }

        }
        return res;
    }
};
