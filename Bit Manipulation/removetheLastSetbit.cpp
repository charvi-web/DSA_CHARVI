class Solution {
public:
    int removelastSetBit(int n) {
        // Your code goes here
        return n&(n-1);
    }
};