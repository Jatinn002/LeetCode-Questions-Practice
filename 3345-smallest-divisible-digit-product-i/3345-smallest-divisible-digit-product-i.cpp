class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int current = n;
            int digitProduct = 1;

            while (current > 0) {
                digitProduct *= current % 10;
                current /= 10;
            }
            if (digitProduct % t == 0) {
                return n;
            }
            n++;
        }
    }
};