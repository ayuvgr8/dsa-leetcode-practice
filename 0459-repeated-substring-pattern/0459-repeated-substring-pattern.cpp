class Solution {
public:
bool repeatedSubstringPattern(string s) {
    int n = s.length();
    
    for (int len = 1; len <= n / 2; len++) {
        if (n % len == 0) {
            string substring = s.substr(0, len);
            string constructed = "";
            
            for (int i = 0; i < n / len; i++) {
                constructed += substring;
            }
            
            if (constructed == s) {
                return true;
            }
        }
    }
    
    return false;
}
};

// int main() {
//     string s1 = "abab";
//     string s2 = "aba";
//     string s3 = "abcabcabcabc";
    
//     cout << boolalpha << repeatedSubstringPattern(s1) << endl;  // Output: true
//     cout << boolalpha << repeatedSubstringPattern(s2) << endl;  // Output: false
//     cout << boolalpha << repeatedSubstringPattern(s3) << endl;  // Output: true
    
//     return 0;
// }
