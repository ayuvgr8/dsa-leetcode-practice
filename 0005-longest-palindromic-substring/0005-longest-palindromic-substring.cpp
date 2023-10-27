class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        
        if (n < 2) {
            return s; // If the string has 0 or 1 character, it's already a palindrome.
        }
        
        string newStr = preProcess(s); // Transform the string to handle even and odd-length palindromes
        
        n = newStr.length();
        vector<int> P(n, 0); // Initialize an array to store the palindrome lengths at each position
        int C = 0; // Center of the rightmost palindrome
        int R = 0; // Right boundary of the rightmost palindrome
        
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i; // Mirror of i with respect to C
            
            // Check if i is within the rightmost palindrome's boundary
            if (R > i) {
                P[i] = min(R - i, P[i_mirror]); // Take the minimum of its mirror and remaining length
            }
            
            // Attempt to expand palindrome centered at i
            while (newStr[i + 1 + P[i]] == newStr[i - 1 - P[i]]) {
                P[i]++;
            }
            
            // If palindrome centered at i expands past R, adjust center and right boundary
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        
        int maxLen = 0; // Length of the longest palindrome
        int centerIndex = 0; // Center of the longest palindrome
        
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }
        
        int start = (centerIndex - maxLen) / 2; // Start index of the longest palindrome in the original string
        return s.substr(start, maxLen);
    }
    
    string preProcess(const string& s) {
        int n = s.length();
        if (n == 0) return "^$"; // Add delimiters to handle even-length palindromes
        string newStr = "^";
        for (int i = 0; i < n; i++) {
            newStr += "#" + s.substr(i, 1);
        }
        newStr += "#$";
        return newStr;
    }
};
