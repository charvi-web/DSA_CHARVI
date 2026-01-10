#include <bits/stdc++.h>
using namespace std;
class Solution {

    vector<vector<string>> ans;
    unordered_map<string,int> m;
    string b;

public:
    void dfs(string word, vector<string>& seq) {
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = m[word];
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (m.count(word) && m[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;

        b = beginWord;
        q.push(beginWord);
        m[beginWord] = 1;
        st.erase(beginWord);

        while (!q.empty()) {
            string word = q.front(); q.pop();
            int steps = m[word];

            if (word == endWord) break;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        st.erase(word);
                        q.push(word);
                        m[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        if (!m.count(endWord)) return ans;

        vector<string> seq = {endWord};
        dfs(endWord, seq);
        return ans;
    }
};
