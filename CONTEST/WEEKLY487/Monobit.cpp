#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countMonobit(int n) {
        int cnt = 1;
        int num = 1;
        while (num<=n)
            {
                cnt++;
                num = (num<<1) | 1  ;     
            }
        return cnt;
    }
};