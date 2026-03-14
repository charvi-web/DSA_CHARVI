#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for (auto it : stones) pq.push(it);
        while(pq.size()>1)
        {
            int A = pq.top();
            pq.pop();
            int B = pq.top();
            pq.pop();
            pq.push(abs(A-B));
        }
        return pq.top();
    }
};