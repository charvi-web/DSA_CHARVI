#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {vector<vector<pair<int,int>>> adj(n);

        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});

        }

        vector<int>ways(n,0);
        vector<long long> dist(n, LLONG_MAX);

        dist[0]=0;
        ways[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

        pq.push({0,0});
        int mod = int(1e9+7);
        while (!pq.empty())
        {
            int node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            if (dis > dist[node]) continue;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                long long edW = it.second;

                if (dist[node]+edW < dist[adjNode])
                {
                    dist[adjNode]=dist[node]+edW;
                    pq.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }

                else if (dist[node]+edW == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            
            }
        }
        return ways[n-1];
    }
};