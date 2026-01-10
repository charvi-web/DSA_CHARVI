#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int src, vector<int> adj[], vector<int>& vis) {
        queue<pair<int,int>> q;
        vis[src] = 1;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it, node});
                }
                else if (it != parent) {
                    // visited and not coming from parent → cycle
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfs(i, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};
