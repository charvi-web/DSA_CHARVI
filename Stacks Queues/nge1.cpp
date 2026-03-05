#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
vector<int>nge(vector<int>& A)
{
    stack<int>st;
    vector<int>ng(A.size(),-1);
    for (int i=A.size()-1;i>=0;i--)
    {
         while (!st.empty() &&  st.top()<=A[i])
        st.pop();

        if (!st.empty()) ng[i]=st.top();
    
     st.push(A[i]);
    }
    return ng;
   
}
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        vector<int>ans;
        for (int j=0;j<nums2.size();j++) {m[nums2[j]]=j;}
        vector<int>a= nge(nums2);
        for (int num: nums1)
        {
            ans.push_back(a[m[num]]);
        }
        return ans;
    }
};