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
    int cnt=0;
    vector<int>vis(n,0);
    for (int i=0;i<n;i++)
    {
        if (!vis[i])
        {
            cnt++;
            depthFirst(i,adj,vis);
        }
    }
cout<<"Number of connected components: "<<cnt;
}