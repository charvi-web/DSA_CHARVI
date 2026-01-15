#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int kDistinctChar(string& s, int k) {
        //your code goes here
        // int n = s.size();
        // int ml=0;
        
        // for (int i=0;i<n;i++)
        // {set<char>st;
        //     for (int j=i;j<n;j++)
        //     {
        //         st.insert(s[j]);
        //         if (st.size()>k)
        //         {
        //             break;
        //         }
        //         ml=max(ml,j-i+1);
        //     }
        // }
        // return ml;
        int n = s.size();
        int l=0;
        int ml=0;
        map<char,int>m;
        for (int r=0;r<n;r++)
        {
            m[s[r]]++;
            if  (m.size()>k)
            {
                m[s[l]]--;
                if (m[s[l]]==0) {m.erase(s[l]);}
                l++;
            }
        if (m.size()<=k) ml = max(ml,r-l+1);
        }
        return ml;
    }
};