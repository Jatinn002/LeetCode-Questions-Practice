class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        reverse(nums.begin(), nums.end() - k);
        reverse(begin(nums) + (n - k), end(nums));
        reverse(nums.begin(), nums.end());
    }
};