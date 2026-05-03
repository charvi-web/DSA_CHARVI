#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void dfs(int i,vector<vector<int>>&adj,vector<int>&vis,int &cnt)
{
    vis[i]=1;
    cnt++;
    for(auto it : adj[i])
    {
        if (!vis[it])
        {
            dfs(it,adj,vis,cnt);
        }
    }
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>>adj(n);
        for (int i=0;i<n;i++)
        {
            long long xi = bombs[i][0];
            long long yi = bombs[i][1];
            long long ri = bombs[i][2];
            for (int j=0;j<n;j++)
            {
                if (i==j) continue;
                long long xj = bombs[j][0];
                long long yj = bombs[j][1];

                long long dx = xi-xj;
                long long dy = yi-yj;

                if (dx*dx+dy*dy<=ri*ri)
                {
                    adj[i].push_back(j);
                }

            }

        }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            vector<int>vis(n,0);
            dfs(i,adj,vis,cnt);
            ans = max(ans,cnt);
        }
        return ans;
    }
};