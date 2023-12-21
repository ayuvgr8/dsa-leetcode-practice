#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int maxSum = nums[0]; // Initialize maxSum with the first element of nums
        int currSum = nums[0]; // Initialize currSum with the first element of nums

        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // Calculate the maximum sum by choosing between the current element and the sum of the current element and the previous subarray
            currSum = std::max(nums[i], currSum + nums[i]);
            // Update the maximum sum encountered so far
            maxSum = std::max(maxSum, currSum);
        }

        return maxSum; // Return the maximum sum of any subarray
    }
};
