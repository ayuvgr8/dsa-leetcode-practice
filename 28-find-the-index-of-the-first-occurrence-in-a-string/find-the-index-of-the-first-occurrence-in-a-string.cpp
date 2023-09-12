// #include <iostream>
// #include <string>
// using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.length();  // Length of haystack string.
        int n = needle.length();    // Length of needle string.

        if (n == 0) {
            return 0;  // Needle is an empty string, so it's always present at index 0.
        }

        for (int i = 0; i <= m - n; ++i) {
            int j;
            // Check if the substring of haystack starting at index i matches the needle.
            for (j = 0; j < n; ++j) {
                if (haystack[i + j] != needle[j]) {
                    break;  // Characters don't match, move to the next starting position in haystack.
                }
            }
            if (j == n) {
                return i;  // All characters in needle match, so return the starting index.
            }
        }

        return -1;  // Needle was not found in haystack.
    }
};

// int main() {
//     Solution solution;
//     string haystack = "sadbutsad";
//     string needle = "sad";
//     int result = solution.strStr(haystack, needle);
    
//     cout << "The first occurrence of the needle is at index: " << result << endl;
    
//     return 0;
// }
