// #include <string>
// #include <vector>
// #include <algorithm>

class Solution {
public:
    std::string sortVowels(std::string s) {
        // Separate vowels and consonants
        std::vector<char> vowels;
        std::string consonants;

        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            } else {
                consonants += c;
            }
        }

        // Sort vowels based on ASCII values
        std::sort(vowels.begin(), vowels.end());

        // Combine vowels and consonants in the original order
        int vowelIndex = 0;
        int consonantIndex = 0;
        for (char& c : s) {
            if (isVowel(c)) {
                c = vowels[vowelIndex++];
            } else {
                c = consonants[consonantIndex++];
            }
        }

        return s;
    }

private:
    bool isVowel(char c) {
        // Check if the character is a vowel (case-insensitive)
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
};
