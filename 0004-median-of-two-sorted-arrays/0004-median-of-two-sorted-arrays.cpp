class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // To ensure nums1 is smaller or equal to nums2, we swap them if necessary.
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        
        int left = 0, right = m, halfLen = (m + n + 1) / 2;
        
        while (left <= right) {
            int partition1 = (left + right) / 2;
            int partition2 = halfLen - partition1;
            
            // Calculate the max values of the left partitions.
            int maxLeft1 = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int maxLeft2 = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            
            // Calculate the min values of the right partitions.
            int minRight1 = (partition1 == m) ? INT_MAX : nums1[partition1];
            int minRight2 = (partition2 == n) ? INT_MAX : nums2[partition2];
            
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Found the correct partition, determine the median.
                if ((m + n) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                // Adjust the partition for nums1 to the left.
                right = partition1 - 1;
            } else {
                // Adjust the partition for nums1 to the right.
                left = partition1 + 1;
            }
        }
        
        // The input arrays are not sorted, so there is no meaningful median.
        return 0.0;
    }
};
