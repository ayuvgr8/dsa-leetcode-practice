class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        // Initialize flags for increasing and decreasing.
        bool increasing = true;
        bool decreasing = true;

        for (int i = 1; i < n; i++) {
            // If the current element is greater than the previous one, it's not decreasing.
            if (nums[i] > nums[i - 1]) {
                decreasing = false;
            }
            // If the current element is less than the previous one, it's not increasing.
            if (nums[i] < nums[i - 1]) {
                increasing = false;
            }
        }

        // If either of the flags is true, the array is monotonic.
        return increasing || decreasing;
    }
};
