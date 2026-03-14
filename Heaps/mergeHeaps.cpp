#include<bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution {
  public:
  void heapify(vector<int>&A,int& n,int &i)
  {
      int largest = i;
      int leftIndex = 2*i+1;
      int rightIndex = 2*i+2;
      if (leftIndex<n && A[largest]<A[leftIndex])
      {
          largest = leftIndex;
      }
      if (rightIndex< n && A[largest]<A[rightIndex])
      {
            largest = rightIndex;          
      }
      if (largest!=i)
      {
          swap(A[largest],A[i]);
          heapify(A,n,largest);
      }
  }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int>c;
        for (auto it : a)
        {
            c.push_back(it);
        }
        for (auto it : b)
        {
            c.push_back(it);
        }
        int p = c.size();
        for (int i=p/2-1;i>=0;i--)
        {
            heapify(c,p,i);
        }
        return c;
    }
};