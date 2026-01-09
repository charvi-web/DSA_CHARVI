#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
void bfs(int node,int n,vector<int>adj[],vector<int>&vis)
{
    
    vis[node]=1;  // 0 isliye nhi rkha kyunki disconnected bhi ho skte h
    queue<int>q;
    q.push(node);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it]=1;  
                q.push(it);
            }
        }

    }
    
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n];
    for (int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (isConnected[i][j]==1 && i!=j)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int cnt=0;
    vector<int>vis(n+1,0);
    for (int i=0;i<n;i++)
    {
        if (!vis[i])
        {
            cnt++;
            bfs(i,n,adj,vis);
        }
    }
    return cnt;
    }
};