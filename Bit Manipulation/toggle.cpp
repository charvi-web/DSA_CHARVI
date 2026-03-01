class Solution {
public:
    int toggleIthBit(int n, int i) {
        // Your code goes here
        return n^(1<<i);
    }
};