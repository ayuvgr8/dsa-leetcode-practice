class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0; // Initialize a long long variable to store the sum of the elements in nums.

        // Calculate the sum of all elements in the nums array.
        for (int num : nums) {
            sum += num;
        }

        // Calculate the absolute difference between the goal and the current sum.
        long long diff = abs(static_cast<long long>(goal) - sum);

        // Calculate the minimum number of elements to be added to reach the goal.
        // Use integer division to ensure that limit is applied properly.
        int result = (diff + limit - 1) / limit;

        return result;
    }
};
