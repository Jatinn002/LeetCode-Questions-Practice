class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int freq[26] = {}, half[26] = {};
        string mid;

        for (char c : s)
            freq[c - 'a']++;

        int halfLen = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            halfLen += half[i];

            if (freq[i] & 1)
                mid = char('a' + i);
        }

        auto countWays = [&](int half[], long long limit) {
            long long ways = 1;
            int total = 0;

            for (int i = 0; i < 26; i++) {
                if (!half[i])
                    continue;

                total += half[i];

                long long n = total;
                long long r = min((long long)half[i], n - half[i]);

                long long comb = 1;

                for (int j = 1; j <= r; j++) {
                    comb = comb * (n - j + 1) / j;
                    if (comb > limit) {
                        comb = limit + 1;
                        break;
                    }
                }

                ways *= comb;

                if (ways > limit)
                    return limit + 1;
            }

            return ways;
        };

        if (countWays(half, k) < k)
            return "";

        string left;
        left.reserve(halfLen);

        for (int pos = 0; pos < halfLen; pos++) {

            for (int c = 0; c < 26; c++) {

                if (!half[c])
                    continue;

                half[c]--;

                long long ways = countWays(half, k);

                if (ways >= k) {
                    left += char('a' + c);
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string ans = left + mid;

        for (int i = halfLen - 1; i >= 0; i--)
            ans += left[i];

        return ans;
    }
};