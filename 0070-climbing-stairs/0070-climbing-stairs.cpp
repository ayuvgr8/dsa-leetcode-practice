class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        
        // Initialize an array to store the number of distinct ways to reach each step.
        vector<int> dp(n + 1, 0);
        
        // There are 2 ways to reach the first step (1 step or 1 step + 0 step).
        dp[1] = 1;
        
        // There are 2 ways to reach the second step (2 steps or 1 step + 1 step).
        dp[2] = 2;
        
        // Calculate the number of ways for each step from step 3 to n.
        for (int i = 3; i <= n; i++) {
            // The number of ways to reach the current step is the sum of the ways to reach the previous two steps.
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        // The final element of the dp array contains the total number of ways to reach the top.
        return dp[n];
    }
};
