class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int freq[26] = {0};

        for (int i = 0; i < n / 2; i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                s[left] = 'a' + i;
                s[n - 1 - left] = 'a' + i;
                left++;
                freq[i]--;
            }
        }
        return s;
    }
};