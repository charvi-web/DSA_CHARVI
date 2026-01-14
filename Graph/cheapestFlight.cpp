#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        vector<pair<int,int>>adj[n];
        vector<int>dist(n,1e9);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        q.push({0,{src,0}});
        dist[src]=0;
        while(!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;
                if (stops>k) continue;
                if (cost+edW<dist[adjNode] && stops<=k) 
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                    
                }
            }
        }
        if (dist[dst]==1e9) return -1;
        return dist[dst];
    }
};