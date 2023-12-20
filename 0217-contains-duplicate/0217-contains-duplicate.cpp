// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_set<int> seen;  // Create an unordered_set to store seen elements
        
//         for (int num : nums) {
//             // If the element is already in the set, return true (duplicate found)
//             if (seen.find(num) != seen.end()) {
//                 return true;
//             }
            
//             seen.insert(num);  // Add the element to the set
//         }
        
//         return false;  // No duplicates found
//     }
// };




// bool containsDuplicate(vector<int>& nums) {
//     int n = nums.size();
    
//     for (int i = 0; i < n; ++i) {
//         for (int j = i + 1; j < n; ++j) {
//             if (nums[i] == nums[j]) {
//                 return true;  // Duplicate found
//             }
//         }
//     }
    
//     return false;  // No duplicates found
//  }
// };





// // Set Approach
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         return nums.size() > set<int>(nums.begin(),nums.end()).size();
//     }
// };




// Shorted Approach
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Sorts the input vector 'nums' in ascending order
        sort(nums.begin(), nums.end());

        // Initializes a boolean variable 'flag' as false to track if a duplicate is found
        bool flag = false;

        // Iterates through the sorted array from index 0 to the second-to-last element
        for (int i = 0; i < nums.size() - 1; i++) {
            // Checks if the current element is equal to the next element
            if (nums[i] == nums[i + 1])
                // If a duplicate is found, returns true immediately
                return true;
        }

        // Returns the value of 'flag', which remains false if no duplicates are found
        return flag;
    }
};