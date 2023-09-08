class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];  // Initialize the first element as the candidate
        int count = 1;            // Initialize the count of the candidate
        
        // Iterate through the array starting from the second element
        for (int i = 1; i < nums.size(); ++i) {
            // If the count becomes 0, update the candidate and reset the count
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                // If the current element is the same as the candidate, increment the count
                count++;
            } else {
                // If the current element is different from the candidate, decrement the count
                count--;
            }
        }
        
        return candidate;  // Return the majority element candidate
    }
};