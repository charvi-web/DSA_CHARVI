#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j]=='X' && !vis[i][j])
                {q.push({i,j});
                vis[i][j]=1;
                cnt++;}

                while (!q.empty()) {
                    int delrow[] =  {-1,0,1,0};
                    int delcol[] = {0,1,0,-1};
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nr = r + delrow[i];
                        int nc = c + delcol[i];
                        if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                            !vis[nr][nc] && board[nr][nc] == 'X') {
                                vis[nr][nc]=1;
                                q.push({nr,nc});
                        }
                    }
                }
            }
        }
        return cnt;
    }
};