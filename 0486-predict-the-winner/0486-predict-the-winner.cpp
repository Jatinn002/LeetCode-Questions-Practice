class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums);

        for (int len = 2; len <= n; len++) {
            for (int i = n - len; i >= 0; i--) {
                int j = i + len - 1;

                int pickLeft = nums[i] - dp[j];
                int pickRight = nums[j] - dp[j - 1];

                dp[j] = max(pickLeft, pickRight);
            }
        }

        return dp[n - 1] >= 0;
    }
};