#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int totalFruits(vector<int>& fruits){
        //your code goes here
        int maxlen=0;
        int n = fruits.size();
        int l=0;
        map<int,int>m;
        // for (int i=0;i<n;i++)
        // {set<int>st;
        //   for(int j=i;j<n;j++)
        //   {
        //     st.add(fruits[j]);
        //     if (st.size()<=2) {maxlen = max(maxlen,j-i+1);}
        //     else break;
        //   }
        // }
        for (int r=0;r<n;r++)
        {
          m[fruits[r]]++;
            
          if (m.size()>2)
          {
            m[fruits[l]]--;
            if (m[fruits[l]]==0) m.erase(fruits[l]);
            l++;
          }
          maxlen = max(maxlen,r-l+1);
        }
        return maxlen;
    }
};