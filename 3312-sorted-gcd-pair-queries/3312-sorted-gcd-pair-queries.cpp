class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);

        for (int x : nums)
            freq[x]++;

        vector<long long> cnt(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d)
                cnt[d] += freq[multiple];
        }

        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            long long pairs = cnt[d] * (cnt[d] - 1) / 2;

            for (int multiple = d * 2; multiple <= mx; multiple += d)
                pairs -= exact[multiple];

            exact[d] = pairs;
        }

        // Prefix counts
        vector<long long> prefix(mx + 1, 0);

        for (int d = 1; d <= mx; d++)
            prefix[d] = prefix[d - 1] + exact[d];

        vector<int> ans;

        for (long long q : queries) {
            // q is 0-indexed
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) -
                    prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};