#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
string processing(string s)
{
    int i=0;
    string ans="";
    int n = s.size();
    while(i<n)
    {int cnt =0;
    char cc  = s[i];
        while (i<n && cc==s[i])
    {
        i++;
        cnt++;
    }
    string counter = to_string(cnt);
    for (auto it : counter)
    {
        ans.push_back(it);
    }
    ans.push_back(cc);
    }
    return ans;
}
    string countAndSay(int n) {
        if (n==1) return "1";
        string s = countAndSay(n-1);
        return processing(s);
    }
};