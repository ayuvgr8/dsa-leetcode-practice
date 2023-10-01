class Solution {
public:
void moveZeroes(vector<int>& nums) {
    int left = 0;
    int right = 0;
    
    while (right < nums.size()) {
        if (nums[right] != 0) {
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
}
};
//int main() {
//     vector<int> nums1 = {0, 1, 0, 3, 12};
//     vector<int> nums2 = {0};
    
//     moveZeroes(nums1);
//     moveZeroes(nums2);
    
//     for (int num : nums1) {
//         cout << num << " ";
//     }
//     cout << endl;  // Output: 1 3 12 0 0
    
//     for (int num : nums2) {
//         cout << num << " ";
//     }
//     cout << endl;  // Output: 0
    
//     return 0;
// }
