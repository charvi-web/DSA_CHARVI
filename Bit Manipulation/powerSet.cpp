#include<bits/stdc++.h>
using namespace std;
Solution {
public:
void f(int ind, vector<int>& nums, int n,vector<int>&ds,vector<vector<int>>&ans)
{

    if (ind==n) {
            ans.push_back(ds);

         if (ds.size()==0) {cout<<"[]";}
            return ;
    }

    ds.push_back(nums[ind]);
    f(ind+1,nums,n,ds,ans);
    ds.pop_back();
    f(ind+1,nums,n,ds,ans);
return ;
}
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // vector<int>ds;
        // vector<vector<int>>ans;
        // f(0,nums,n,ds,ans);
        // return ans;
        int noOfSubsets = 1<<n;
        vector<vector<int>>ans;
        for (int i=0;i<noOfSubsets;i++)
        {
            vector<int>list;
            for (int j=0;j<n;j++)
            {
                if (i&(1<<j))
                {
                    list.push_back(nums[j]);
                }
            }
            ans.push_back(list);
        }
        return ans;
    }
};