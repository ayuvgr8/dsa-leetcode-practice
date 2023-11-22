class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        
//     }
// };
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Loop through each element in the vector
        for (int i = 0; i < nums.size(); i++) {
            // Loop through the remaining elements after i
            for (int j = i + 1; j < nums.size(); j++) {
                // Check if the sum of the current and the other element is equal to target
                if (nums[i] + nums[j] == target) {
                    // If found, return the indices as a vector
                    return {i, j};
                }
            }
        }
        // If no such pair exists, return empty vector
        return {};
    }
};