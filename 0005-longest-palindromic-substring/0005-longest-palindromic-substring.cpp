// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) {
            return "";
        }

        // Create a dynamic 2D boolean vector to store whether substrings are palindromes.
        // dp[i][j] will be 'true' if the substring from index 'i' to 'j' is a palindrome.
        // Initialize all entries to 'false'.
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0; // Starting index of the longest palindromic substring found so far.
        int maxLen = 1; // Length of the longest palindromic substring found so far.

        // All substrings of length 1 are palindromes, so set dp[i][i] to 'true'.
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        // Check for palindromes of length 2.
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check for palindromes of length 3 or more.
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1; // Ending index of the current substring.
                
                // Check if the current substring is a palindrome and its inner substring is also a palindrome.
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    
                    // Update the start index and maximum length if a longer palindrome is found.
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        // Extract and return the longest palindromic substring.
        return s.substr(start, maxLen);
    }
};

// int main() {
//     Solution solution;
//     string s1 = "babad";
//     string result1 = solution.longestPalindrome(s1);
    
//     cout << "Longest palindromic substring in s1: " << result1 << endl;

//     string s2 = "cbbd";
//     string result2 = solution.longestPalindrome(s2);
    
//     cout << "Longest palindromic substring in s2: " << result2 << endl;

//     return 0;
// }
