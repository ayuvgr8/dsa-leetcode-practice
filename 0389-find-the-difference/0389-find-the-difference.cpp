class Solution {
public:
char findTheDifference(string s, string t) {
    unordered_map<char, int> charCount;

    // Count the occurrences of each character in string s
    for (char c : s) {
        charCount[c]++;
    }

    // Subtract the occurrences of each character in string t
    for (char c : t) {
        if (charCount.find(c) == charCount.end() || charCount[c] == 0) {
            return c;
        }
        charCount[c]--;
    }

    return ' '; // Default return if no difference found
}

};

// int main() {
//     string s1 = "abcd";
//     string t1 = "abcde";
    
//     string s2 = "";
//     string t2 = "y";

//     cout << findTheDifference(s1, t1) << endl;  // Output: "e"
//     cout << findTheDifference(s2, t2) << endl;  // Output: "y"

//     return 0;
// }