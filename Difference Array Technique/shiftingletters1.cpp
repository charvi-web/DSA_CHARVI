#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();
        int tshift = 0;
        for (int i=n-1;i>=0;i--)
        {
            tshift = (tshift + shifts[i])%26;
            s[i] = ((s[i]-'a')+tshift)%26+'a';
        }
        return s;
    }
};