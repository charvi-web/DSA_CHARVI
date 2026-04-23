#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void f (int ind,vector<vector<int>>&ans,vector<int>& candidates,vector<int>&A,int target)
{
    if (ind == candidates.size())
    {
        if (target==0)
        {
            ans.push_back(A);
        }
        return;
    }
    if (candidates[ind]<=target)
    {A.push_back(candidates[ind]);
    f(ind,ans,candidates,A,target-candidates[ind]);
    A.pop_back();}
    f(ind+1,ans,candidates,A,target);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>A;
        f(0,ans,candidates,A,target);
        return ans;
    }
};