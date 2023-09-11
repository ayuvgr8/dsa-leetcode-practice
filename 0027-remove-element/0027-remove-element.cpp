class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int k = 0; // Represents the index where the next non-val element should be placed
    
    // Iterate through the vector
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i]; // Move non-val element to the correct position
            k++; // Increment k to point to the next position
        }
    }
    
    return k; // Return the new length of the array after removal
}
};

// #include <iostream>
// #include <vector> // Include the vector library for dynamic arrays

// using namespace std;



// int main() {
//     // Test the function with example input
//     vector<int> nums = {3, 2, 2, 3}; // Input array
//     int val = 3; // Value to remove
    
//     int k = removeElement(nums, val); // Call the function
    
//     // Display the updated array
//     cout << "Updated array: ";
//     for (int i = 0; i < k; i++) {
//         cout << nums[i] << " ";
//     }
//     cout << endl;
    
//     return 0;
// }
