#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        // vector<int>iKnow(n,0);
        // vector<int>knowMe(n,0);
        // for (int i=0;i<n;i++)
        // {
        //     for (int j=0;j<n;j++)
        //     {
        //         if (M[i][j]==1)
        //         {
         //           iKnow[i]++;
        //             knowMe[j]++;
        //             
        //         }
        //     }
        // }
        // for (int i=0;i<n;i++)
        // {
        //     if (iKnow[i]==0 && knowMe[i]==n-1) return i;
        //     else return -1;
        // }
        int top = 0;
        int down = n-1;
        while (top<down)
        {
            if (M[top][down]==1)
            {
                top++;
            }
            else
            {
                down--;
            }
        }
        int cand = top;
        for (int i=0;i<n;i++)
        {
            if (i==cand) continue;
            if (M[cand][i]==1 || M[i][cand]==0) return -1;
        }
        return cand;
    }
};
