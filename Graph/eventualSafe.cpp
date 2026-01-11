#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(int src, vector<vector<int>>adj, vector<int>& vis,
             vector<int>& pathVis, vector<int>& checker) {
        vis[src] = 1;
        pathVis[src] = 1;
        for (auto it : adj[src]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis, checker) == true) {

                    checker[it] = 0;
                    return true;
                }
            }

            else if (pathVis[it]) {
                checker[it] = 0;
                return true;
            }
        }
        checker[src] = 1;
        pathVis[src] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> checker(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathVis, checker);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (checker[i] == 1) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};