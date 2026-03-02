#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>m;
        for (int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if (m[s[i]]==1) return i;
        }
        return -1;
    }
};