// #include <iostream>
// #include <vector>

// using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // If the middle element is equal to the target, return its index
            if (nums[mid] == target) {
                return mid;
            }

            // Check which side of the array is sorted
            if (nums[left] <= nums[mid]) {
                // Left side is sorted

                // Check if the target is within the left sorted side
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1; // Adjust the right boundary
                } else {
                    left = mid + 1; // Adjust the left boundary
                }
            } else {
                // Right side is sorted

                // Check if the target is within the right sorted side
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1; // Adjust the left boundary
                } else {
                    right = mid - 1; // Adjust the right boundary
                }
            }
        }

        return -1; // Target not found
    }
};

// int main() {
//     Solution solution;

//     // Test case 1
//     vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
//     int target1 = 0;
//     cout << "Test case 1: " << solution.search(nums1, target1) << endl; // Expected output: 4

//     // Test case 2
//     vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
//     int target2 = 3;
//     cout << "Test case 2: " << solution.search(nums2, target2) << endl; // Expected output: -1

//     // Test case 3
//     vector<int> nums3 = {1};
//     int target3 = 0;
//     cout << "Test case 3: " << solution.search(nums3, target3) << endl; // Expected output: -1

//     return 0;
// }
