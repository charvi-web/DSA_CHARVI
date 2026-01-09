#include<bits/stdc++.h>
using namespace std;
void depthFirst(int node,vector<vector<int>>&adj,vector<int>&vis)
{
    vis[node]=1;
    cout<<node<<" ";
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            depthFirst(it,adj,vis);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>vis(n,0);
    depthFirst(0,adj,vis);
}