// #include <iostream>
// #include <string>
// using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;  // Initialize the length of the last word to 0.
        int i = s.size() - 1;  // Start from the end of the string.

        // Skip trailing spaces if any.
        while (i >= 0 && s[i] == ' ') {
            i--;
        }

        // Count the characters of the last word.
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;  // Return the length of the last word.
    }
};

// int main() {
//     Solution solution;
//     string s1 = "Hello World";
//     int result1 = solution.lengthOfLastWord(s1);
    
//     cout << "The length of the last word in s1 is: " << result1 << endl;

//     string s2 = "   fly me   to   the moon  ";
//     int result2 = solution.lengthOfLastWord(s2);
    
//     cout << "The length of the last word in s2 is: " << result2 << endl;

//     string s3 = "luffy is still joyboy";
//     int result3 = solution.lengthOfLastWord(s3);
    
//     cout << "The length of the last word in s3 is: " << result3 << endl;
    
//     return 0;
// }
