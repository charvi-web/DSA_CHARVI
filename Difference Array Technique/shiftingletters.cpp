#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int>diff(n,0);
        for (auto &it : shifts)
        {
            int left = it[0];
            int right = it[1];
            int shift = it[2];
            int x;
            if (shift==0)
            {
                x=-1;
            }
            else {x=1;}
            diff[left]+=x;
            if (right+1<n){diff[right+1]-=x;}
            
        }
        for (int i=1;i<n;i++)
        {
            diff[i]+=diff[i-1];
        }
        for (int i=0;i<n;i++)
        {
            int shift = diff[i]%26;
            if (shift<0)
            {
                shift+=26;
            }
            
            s[i]=(((s[i]-'a')+shift)%26)+'a';
        }
return s;
    }
};