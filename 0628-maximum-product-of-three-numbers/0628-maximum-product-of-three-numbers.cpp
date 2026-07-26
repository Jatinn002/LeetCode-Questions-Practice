class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int first = INT_MIN;
        int second = INT_MIN;
        int third = INT_MIN;

        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for (int num : nums) {

            if (num > first) {
                third = second;
                second = first;
                first = num;
            } else if (num > second) {
                third = second;
                second = num;
            } else if (num > third) {
                third = num;
            }

            if (num < smallest) {
                secondSmallest = smallest;
                smallest = num;
            } else if (num < secondSmallest) {
                secondSmallest = num;
            }
        }

        return max(first * second * third, first * smallest * secondSmallest);
    }
};