// #include <vector>
// #include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(std::vector<int>& nums) {
        // Initialize variables to store the maximum product, minimum product, and the final result
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // Store the current maximum product to check for negatives
            int tempMax = maxProd;

            // Update the maximum product by considering three possibilities: 
            // 1. Current element itself
            // 2. Maximum product so far * current element
            // 3. Minimum product so far * current element (to handle negative values)
            maxProd = max(nums[i], std::max(tempMax * nums[i], minProd * nums[i]));

            // Update the minimum product by considering the same three possibilities as above
            minProd = min(nums[i], min(tempMax * nums[i], minProd * nums[i]));

            // Update the final result to keep track of the maximum product encountered so far
            result = max(result, maxProd);
        }

        return result; // Return the maximum product
    }
};
