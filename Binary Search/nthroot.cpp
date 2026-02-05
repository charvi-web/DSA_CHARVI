#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int func(int mid,int N,int M)
{
    long long ans = 1;
    for (int i=1;i<=N;i++)
    {
        ans=ans*mid;
        if (ans>M) return 2;
    }  
    if (ans==M) return 1;
  
    return 0;
}
  int NthRoot(int N, int M) {
       int s = 1;
       int e  = M;
       while(s<=e)
       {
        int mid = s+(e-s)/2;
        if (func(mid,N,M)==1) return mid;
        else if (func(mid,N,M)==0) s=mid+1;
        else e=mid-1;
       }
       return -1;
    }
};
