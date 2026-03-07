#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int countGreater(int index, vector<int> &A)
{
    int n = A.size();
    int cnt = 0;
    for (int i=index+1;i<n;i++)
    {
        if (A[i]>A[index])
        {
            cnt++;
        }
    }
    return cnt;
}
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
        
        vector<int>ans;        
        for (auto &it : indices)
        {
            ans.push_back(countGreater(it,arr));
        }
        return ans;
    }
};