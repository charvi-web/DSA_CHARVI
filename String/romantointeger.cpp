#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int value_helper(char c)
{
    if (c=='I')               return 1;
    else if (c=='V')          return 5;
    else if (c=='X')          return 10;
    else if (c=='L')          return 50;
    else if (c=='C')          return 100;
    else if (c=='D')          return 500;
    return 1000;
}
    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();
        for (int i=0;i<n;i++)
        {
            int curr = value_helper(s[i]);
            if (i+1<n && curr<value_helper(s[i+1])) ans-=curr;
            else ans+=curr;
        }
        return ans;
    }
};