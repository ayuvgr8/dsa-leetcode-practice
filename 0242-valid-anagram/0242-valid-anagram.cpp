class Solution {
public:
    
bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    vector<int> sFreq(26, 0);  // Array to store character frequencies

    // Count character frequencies in string s
    for (char c : s) {
        sFreq[c - 'a']++;
    }

    // Decrement character frequencies for string t
    for (char c : t) {
        if (sFreq[c - 'a'] == 0) {
            return false;  // If a character is not in s, they can't be anagrams
        }
        sFreq[c - 'a']--;
    }

    // Check if all character counts are zero
    for (int count : sFreq) {
        if (count != 0) {
            return false;
        }
    }

    return true;
}
};
// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;


// int main() {
//     string s1 = "anagram";
//     string t1 = "nagaram";

//     string s2 = "rat";
//     string t2 = "car";

//     cout << boolalpha << isAnagram(s1, t1) << endl;  // Output: true
//     cout << boolalpha << isAnagram(s2, t2) << endl;  // Output: false

//     return 0;
// }
