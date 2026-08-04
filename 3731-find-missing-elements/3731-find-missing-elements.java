class Solution {
    public List<Integer> findMissingElements(int[] nums) {
        Set<Integer> set = new HashSet<>();

        int mn = Integer.MAX_VALUE;
        int mx = Integer.MIN_VALUE;

        for (int x : nums) {
            set.add(x);
            mn = Math.min(mn, x);
            mx = Math.max(mx, x);
        }

        List<Integer> ans = new ArrayList<>();
        for (int i = mn + 1; i < mx; i++) {
            if (!set.contains(i))
                ans.add(i);
        }
        return ans;
    }
}