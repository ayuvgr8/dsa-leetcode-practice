class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<long long> dp(n, 1); // Initialize dp array with 1
        
        sort(arr.begin(), arr.end()); // Sort the array in ascending order
        
        unordered_map<int, int> index; // Map values to their indices in the array
        
        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int factor = arr[i] / arr[j];
                    if (index.find(factor) != index.end()) {
                        // If the factor exists in the array
                        int k = index[factor];
                        dp[i] = (dp[i] + dp[j] * dp[k]) % MOD;
                    }
                }
            }
        }
        
        long long total = 0;
        for (long long num : dp) {
            total = (total + num) % MOD;
        }
        
        return static_cast<int>(total);
    }
};
