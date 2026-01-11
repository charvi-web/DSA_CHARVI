#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
bool check(int src,vector<int> adj[],vector<int>&vis,vector<int>&pathVis)
{
    vis[src]=1;
    pathVis[src]=1;
    for(auto it:adj[src])
    {
        if (!vis[it])
        {
            if (check(it,adj,vis,pathVis)==true)
            {return true;}

            
        }
        else if (pathVis[it])
            {
                return true;
            }
    }
    pathVis[src]=0;
    return false;
}
    bool isCyclic(int N, vector<int> adj[]) {
        vector<int>vis(N,0);
        vector<int>pathVis(N,0);
        for(int i=0;i<N;i++)
        {
            if (!vis[i])
            {
                if (check(i,adj,vis,pathVis)==true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
