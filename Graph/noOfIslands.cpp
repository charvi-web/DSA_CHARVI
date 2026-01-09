#include<bits/stdc++.h>
using namespace std;
 class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    cnt++;                  // new island
                    q.push({i, j});
                    vis[i][j] = 1;

                    // BFS for this island
                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();

                        int delrow[] = {-1, 0, 1, 0};
                        int delcol[] = {0, 1, 0, -1};

                        for (int k = 0; k < 4; k++) {
                            int nrow = row + delrow[k];
                            int ncol = col + delcol[k];

                            if (nrow >= 0 && nrow < n &&
                                ncol >= 0 && ncol < m &&
                                grid[nrow][ncol] == '1' &&
                                !vis[nrow][ncol]) {

                                vis[nrow][ncol] = 1;
                                q.push({nrow, ncol});
                            }
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
