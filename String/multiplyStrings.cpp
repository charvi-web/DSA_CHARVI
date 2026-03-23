#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        vector<int>ans(m+n,0);
        for (int i=0;i<m;i++)
        {
            int a = num1[i]-'0';
            for (int j=0;j<n;j++)
            {
                int b = num2[j]-'0';
                ans[i+j]+=a*b;
                ans[i+j+1] += ans[i+j]/10;
                ans[i+j]=ans[i+j]%10;
            }

        }
        string result="";
        for (int i=ans.size()-1;i>=0;i--)
        {
            if (result.empty() && ans[i]==0) continue;
            result+=(ans[i]+'0');
        }
        if (result=="") return "0";
        return result;
    }
};