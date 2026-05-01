#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxicnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                    int cnt = 1;

                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        int delrow[] = {-1, 0, 1, 0};
                        int delcol[] = {0, 1, 0, -1};
                        for (int x = 0; x < 4; x++) {
                            int nrow = row + delrow[x];
                            int ncol = col + delcol[x];
                            if (nrow >= 0 && nrow < n && ncol >= 0 &&
                                ncol < m && !vis[nrow][ncol] &&
                                grid[nrow][ncol] == 1) {
                                cnt++;
                                q.push({nrow, ncol});
                                vis[nrow][ncol] = 1;
                            }
                        }
                    }
                    maxicnt = max(maxicnt, cnt);
                }
            }
        }
        return maxicnt;
    }
};