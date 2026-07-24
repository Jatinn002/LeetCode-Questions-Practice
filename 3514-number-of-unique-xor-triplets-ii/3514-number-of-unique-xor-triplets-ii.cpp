class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int mx = *max_element(nums.begin(), nums.end());

        int limit = 1;
        while (limit <= mx)
            limit <<= 1;

        vector<bool> pair(limit, false);
        vector<bool> triplet(limit, false);

        // All possible XOR of two numbers
        for (int a : nums)
            for (int b : nums)
                pair[a ^ b] = true;

        // XOR with third number
        for (int x = 0; x < limit; x++) {
            if (!pair[x])
                continue;

            for (int num : nums)
                triplet[x ^ num] = true;
        }

        return count(triplet.begin(), triplet.end(), true);
    }
};