#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start^goal;
        int cnt = 0 ;
        while (ans)
        {
            cnt++;
            ans=ans&(ans-1);
        }
        return cnt;
    }
};