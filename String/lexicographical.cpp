#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void solve(string curr, string &result,int n,int &k,int &cnt)
{
    if (n==curr.size()) {
        cnt++;
        if (cnt==k)
        {
            result=curr;
            
        }
        return;
    }
    for (char c = 'a';c<='c';c++)
    {
        if (!curr.empty() && curr.back()==c)
        {
            continue;
        }
        curr.push_back(c);
        solve(curr,result,n,k,cnt);
        curr.pop_back();
    }
}
    string getHappyString(int n, int k) {
        int cnt=0;
        string result;
        string curr="";
        solve(curr,result,n,k,cnt);
        return result;
    }
};