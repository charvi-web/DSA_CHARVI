#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>m;
        int maxlen = 0;
        int prefix=0;
        m[0]=-1;
        for (int i=0;i<n;i++)
        {
            if (nums[i]==0) {prefix-=1;}
            else {prefix+=1;}

            if (m.find(prefix)!=m.end())
            {
                maxlen = max(maxlen,i-m[prefix]);
            }
            //first occurence only
            else m[prefix]=i;
        }
        return maxlen;
    }
};