class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        bool seen[101] = {};

        int mn = 100, mx = 0;

        for (int x : nums) {
            seen[x] = true;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        vector<int> ans;
        for (int i = mn + 1; i < mx; i++) {
            if (!seen[i])
                ans.push_back(i);
        }
        return ans;
    }
};