#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        for(int &num : nums)
        {
            int rem = num%3;
            // if (rem==0) operations+=0;
            // else if (rem==1) operations+=1;
            // else {operations+=1;}
            operations+= min(rem,3-rem);
        }
        return operations;
    }
};