class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // Initialize minimum price to a large value
        int maxProfit = 0;        // Initialize maximum profit to 0
        
        for (int price : prices) {
            minPrice = min(minPrice, price);   // Update minimum price if needed
            maxProfit = max(maxProfit, price - minPrice); // Calculate and update maximum profit
        }
        
        return maxProfit;  // Return the maximum profit
    }
};
