// #include <iostream>
// #include <string>
// using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIdx = 0; // Initialize an index for string s.
        int tIdx = 0; // Initialize an index for string t.

        while (sIdx < s.size() && tIdx < t.size()) {
            if (s[sIdx] == t[tIdx]) {
                sIdx++; // Move the index for string s.
            }
            tIdx++; // Always move the index for string t.
        }

        // If we've reached the end of s, it means s is a subsequence of t.
        return sIdx == s.size();
    }
};

// int main() {
//     Solution solution;
//     string s1 = "abc";
//     string t1 = "ahbgdc";
//     bool result1 = solution.isSubsequence(s1, t1);
    
//     cout << "Is s1 a subsequence of t1? " << (result1 ? "Yes" : "No") << endl;

//     string s2 = "axc";
//     string t2 = "ahbgdc";
//     bool result2 = solution.isSubsequence(s2, t2);
    
//     cout << "Is s2 a subsequence of t2? " << (result2 ? "Yes" : "No") << endl;
    
//     return 0;
// }
