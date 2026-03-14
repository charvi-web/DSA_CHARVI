#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        int cost = 0;
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for (auto it : arr) pq.push(it);
        while(pq.size()>1)
        {
            int A = pq.top();
            pq.pop();
            int B = pq.top();
            pq.pop();
            int sum = A+B;
            cost+=sum;
            pq.push(sum);
        }
        return cost;
    }
};