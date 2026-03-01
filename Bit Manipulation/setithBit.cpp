class Solution {
public:
    int setIthBit(int n, int i) {
        // Your code goes here
        return n|(1<<i);
    }
};