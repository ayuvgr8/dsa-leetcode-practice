// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int max1 = INT_MIN, max2 = INT_MIN;

//         for (int num : nums) {
//             if (num >= max1) {
//                 max2 = max1;
//                 max1 = num;
//             } else if (num > max2) {
//                 max2 = num;
//             }
//         }

//         return (max1 - 1) * (max2 - 1);
//     }
// };
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN; // Initialize two variables to store the maximum and second maximum values

        for (int num : nums) { // Iterate through the elements of the input vector 'nums'
            if (num >= max1) { // If the current number is greater than or equal to the current maximum
                max2 = max1;   // Store the previous maximum in the second maximum
                max1 = num;    // Update the maximum with the current number
            } else if (num > max2) { // If the current number is greater than the second maximum
                max2 = num;    // Update the second maximum with the current number
            }
        }

        return (max1 - 1) * (max2 - 1); // Calculate and return the product of (max1 - 1) and (max2 - 1)
    }
};
