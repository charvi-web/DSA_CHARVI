#Include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void f(int ind,vector<vector<int>>&ans,vector<int>&A,vector<int>& candidates,int target)
{
    
    if (target==0)
        {
            ans.push_back(A);
            return ;
        }
    for (int i = ind;i<candidates.size();i++)
    {
        if (i>ind && candidates[i]==candidates[i-1]) continue;
        if (candidates[i]>target) break;
        A.push_back(candidates[i]);
        f(i+1,ans,A,candidates,target-candidates[i]);
        A.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>A;
        f(0,ans,A,candidates,target);
        return ans;
    }
};