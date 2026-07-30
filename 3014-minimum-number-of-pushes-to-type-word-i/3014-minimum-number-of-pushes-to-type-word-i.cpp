class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        int push = 1;

        for (int i = 0; i < n / 8; i++) {
            ans += push * 8;
            push++;
        }

        ans += push * (n % 8);

        return ans;
    }
};