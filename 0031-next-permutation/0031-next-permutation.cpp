class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Find the first index 'i' from right to left such that nums[i] < nums[i+1].
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // If 'i' is still non-negative, find the first index 'j' from right to left
        // such that nums[j] > nums[i].
        if (i >= 0) {
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Swap nums[i] and nums[j].
            swap(nums[i], nums[j]);
        }

        // Reverse the subarray nums[i+1:n-1] to make it in ascending order.
        reverse(nums.begin() + i + 1, nums.end());
    }
};


// Here's a step-by-step explanation of the code:

// We start by finding the first index 'i' from right to left such that nums[i] < nums[i+1]. This step is crucial because it identifies the position where we can make a change to get the next greater permutation.
// If 'i' is still non-negative, it means there is a valid position to make a change. We then find the first index 'j' from right to left such that nums[j] > nums[i]. This is the position where we will swap elements.
// We swap nums[i] and nums[j] to make the change. This step ensures that the new permutation is greater than the original one but still lexicographically smaller than any other permutation that can be formed by rearranging the elements.
// Finally, to complete the permutation, we reverse the subarray nums[i+1:n-1]. This step is necessary to ensure that we get the next permutation in lexicographical order.
// This algorithm allows us to find the next permutation in-place with constant extra memory, as required by the problem statement.