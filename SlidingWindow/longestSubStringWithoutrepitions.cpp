#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxlen = 0;
        int l = 0;

        vector<int> hash(256, -1);

        for (int r = 0; r < n; r++) {
            if (hash[s[r]] != -1 && hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }

            maxlen = max(maxlen, r - l + 1);
            hash[s[r]] = r;
        }

        return maxlen;
    }
};
