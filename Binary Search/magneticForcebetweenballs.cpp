#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool f(vector<int>&position,int m,int mid)
{
    int b=1;
    int last = position[0];
    for(int i=1;i<position.size();i++)
    {
        if (position[i]-last>=mid)
        {
            b++;
            last=position[i];
        }
    }
    return b>=m;
}
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int s=1;
        int ans =0;
        int e=*max_element(position.begin(),position.end())-*min_element(position.begin(),position.end());
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if (f(position,m,mid))
            {
                ans=mid;
                s=mid+1;
            }
            else e =mid-1;
        }
        return ans;
    }
};