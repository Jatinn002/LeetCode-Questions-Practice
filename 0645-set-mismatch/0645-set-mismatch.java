class Solution {
    public int[] findErrorNums(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            int correctIndex = nums[i] - 1;
            if (nums[i] != nums[correctIndex]) {
                swap(nums, i, correctIndex);
            } else {
                i++;
            }
        }
        // search for first  missing number
        for (int index = 0; index < nums.length; index++) {
            if (nums[index] != index + 1) {
                return new int[] { nums[index], index + 1 };
            }
        }
        return new int[] { -1, -1 };
    }

    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}