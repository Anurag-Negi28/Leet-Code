class Solution {
public:
    int minBitFlips(int start, int goal) {
        // XOR to find differing bits
        int xorResult = start ^ goal;
        int count = 0;
        // Count the number of 1s in xorResult (differing bits)
        while (xorResult) {
            count += xorResult & 1;  // Increment if the last bit is 1
            xorResult >>= 1;         // Shift right to process the next bit
        }
        return count;
    }
};