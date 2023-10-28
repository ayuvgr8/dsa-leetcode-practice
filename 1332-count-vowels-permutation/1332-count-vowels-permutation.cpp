class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1000000007;
        
        // Create a 2D array to represent the possible transitions between vowels.
        // transitions[i][j] represents the number of strings ending with vowel j
        // when the last character is vowel i.
        vector<vector<long long>> transitions(5, vector<long long>(5, 0));
        
        // Initialize the transitions based on the rules.
        transitions[0][1] = 1; // 'a' can only be followed by 'e'
        transitions[1][0] = 1; // 'e' can be followed by 'a'
        transitions[1][2] = 1; // 'e' can also be followed by 'i'
        transitions[2][0] = 1; // 'i' can be followed by 'a'
        transitions[2][1] = 1; // 'i' can also be followed by 'e'
        transitions[2][3] = 1; // 'i' can be followed by 'o'
        transitions[2][4] = 1; // 'i' can also be followed by 'u'
        transitions[3][2] = 1; // 'o' can be followed by 'i'
        transitions[3][4] = 1; // 'o' can also be followed by 'u'
        transitions[4][0] = 1; // 'u' can only be followed by 'a'

        // Create a 2D DP array to store the counts for each character at each position.
        // dp[i][j] represents the number of strings of length i ending with vowel j.
        vector<vector<long long>> dp(n, vector<long long>(5, 0));
        
        // Initialize the base cases for the DP array.
        for (int j = 0; j < 5; ++j) {
            dp[0][j] = 1; // There is one string of length 1 ending with each vowel.
        }
        
        // Fill in the DP array using the transitions and modulo to avoid overflow.
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 5; ++j) {
                for (int k = 0; k < 5; ++k) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k] * transitions[k][j]) % MOD;
                }
            }
        }
        
        // Sum up the counts for all vowels at the last position to get the total count.
        long long totalCount = 0;
        for (int j = 0; j < 5; ++j) {
            totalCount = (totalCount + dp[n - 1][j]) % MOD;
        }
        
        return static_cast<int>(totalCount);
    }
};
