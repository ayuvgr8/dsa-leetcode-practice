class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product = 1; // Initialize the product as 1.
        
        for (int num : nums) {
            if (num == 0) {
                return 0; // If any number is 0, the product will be 0, and the sign is 0.
            } else if (num < 0) {
                product *= -1; // If the number is negative, flip the sign of the product.
            }
        }
        
        return product; // Return the sign of the product.
    }
};
