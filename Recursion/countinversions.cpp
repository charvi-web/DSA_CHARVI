#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  int merge(vector<int>&A,int l,int mid,int h)
  {
      vector<int>ans;
int left =l;
int right = mid+1;
  int cnt=0;

while (left<=mid && right<=h)
{
    if (A[left] <= A[right])
    {
        ans.push_back(A[left]);
        left++;
        
    }
    else 
    {
        ans.push_back(A[right]);
        cnt+=(mid-left+1);
        right++;
    }
}
while (left<=mid)
{
    ans.push_back(A[left]);
        left++;
    
}
while (right<=h)
{
    ans.push_back(A[right]);
        right++;
}

for(int i=l;i<=h;i++)
{
    A[i]=ans[i-l];
}
return cnt;
  }
  int mergeSort(vector<int>&A,int l,int h)
  {      if (l>=h) return 0;

      int cnt=0;
      int mid = (l+h)/2;
      cnt+=mergeSort(A,l,mid);
      cnt+=mergeSort(A,mid+1,h);
      cnt+=merge(A,l,mid,h);
      return cnt;
      
  }
    int inversionCount(vector<int> &arr) {
        // Code Here
        return mergeSort(arr,0,arr.size()-1);
        
    }
};