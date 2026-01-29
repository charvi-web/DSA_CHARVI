#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hash(256, 0);
        for (char c : t) hash[c]++;

        int l = 0, cnt = 0;
        int minLen = INT_MAX;
        int start = -1;

        for (int r = 0; r < s.size(); r++) {
            if (hash[s[r]] > 0) cnt++;
            hash[s[r]]--; //insert kr rhe h toh decrement hi krenge 

            while (cnt == t.size()) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) cnt--;
                l++;
            }
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};
