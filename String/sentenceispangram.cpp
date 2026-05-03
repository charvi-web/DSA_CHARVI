#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int>alpho(26,0);
        for(int i=0;i<sentence.size();i++)
        {
            alpho[sentence[i]-'a']++;
        }
        for (int i=0;i<26;i++)
        {
            if (alpho[i]==0) return false;
        }
        return true;
    }
};