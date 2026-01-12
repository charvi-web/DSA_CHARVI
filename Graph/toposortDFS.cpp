#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
void dfs(int node,vector<int>adj[],stack<int>&s,vector<int>&vis)
{
    vis[node]=1;
    for(auto it :adj[node])
    {
        if (!vis[it])
        {
            dfs(it,adj,s,vis);
        }
    }
    s.push(node);
}
    vector<int> topoSort(int V, vector<int> adj[]){
        vector<int>vis(V,0);
        stack<int>s;
        vector<int>ans;
        for(int i=0;i<V;i++)
        {
            if (!vis[i])
            {
                dfs(i,adj,s,vis);
            }
        }
        
    
        
        while(!s.empty())
        {
            int e = s.top();
            s.pop();
            ans.push_back(e);
        }
        return ans;
        
    }
};
