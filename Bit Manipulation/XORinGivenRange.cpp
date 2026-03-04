#include<bits/stdc++.h>
using namespace std;
class Solution{	
public:

    int func(int N)
    {
        if (N < 0) return 0;   // important safety
        
        if (N % 4 == 0) return N;
        if (N % 4 == 1) return 1;
        if (N % 4 == 2) return N + 1;
        return 0;              // when N % 4 == 3
    }

    int findRangeXOR(int l, int r){
        return func(r) ^ func(l - 1);
    }
};