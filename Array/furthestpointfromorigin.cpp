#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int Rcount = 0;
        int Lcount = 0;
        int _count = 0;
        for (int i=0;i<n;i++)
        {
            if (moves[i]=='L') Lcount++;
            else if (moves[i]=='R') Rcount++;
            else _count++;
        }
        return abs(Lcount-Rcount) + _count;
    }
};