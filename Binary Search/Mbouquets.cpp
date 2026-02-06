#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
bool func(int mid, vector<int>& bloomDay, int m, int k)
{int cnt=0;
int nb=0;
    for (auto it : bloomDay)
    {
        if (mid>=it) {cnt++;}
        else {nb+=cnt/k;
        cnt=0;}
    }
            nb+=cnt/k;

    if (nb>=m) return true;
    else return false;
   
}

    int minDays(vector<int>& bloomDay, int m, int k) {
        int ans =-1;
        if ((long long)m*k>bloomDay.size()) return -1;
        int s = *min_element(bloomDay.begin(),bloomDay.end());
        int e = *max_element(bloomDay.begin(),bloomDay.end());
        while (s<=e)
        {
            int mid = s+(e-s)/2;
            if (func(mid,bloomDay,m,k)==true) {ans= mid;
            e=mid-1;}
            else s=mid+1;
        }
        return ans;
    }
};