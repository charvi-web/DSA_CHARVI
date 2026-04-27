#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool validPalindrome(string str)
{
    int n = str.size();
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        if (str[i]!=str[j]) return false;
        i++;
        j--;
    }
    return true;
}
void f(string s,vector<string>&p,vector<vector<string>>&ans,)
{
    if (s.size()==0)
    {
        ans.push_back(p);
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        string a = s.substr(0,i+1);
        if (validPalindrome(a))
        {
            p.push_back(a);
            f(s,p,ans);
            p.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>p;
        f(s,p,ans);
        return ans;
    }
};