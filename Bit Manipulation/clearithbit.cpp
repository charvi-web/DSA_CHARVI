class Solution {
public:
    int clearIthBit(int n, int i) {
        // Your code goes here
        return n&~(1<<i);
    }
};