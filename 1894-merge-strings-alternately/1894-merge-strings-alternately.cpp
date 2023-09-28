class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    int i = 0, j = 0;
    string result = "";

    // Iterate through both strings, adding characters alternately
    while (i < word1.size() || j < word2.size()) {
        if (i < word1.size()) {
            result += word1[i];
            i++;
        }
        if (j < word2.size()) {
            result += word2[j];
            j++;
        }
    }

    return result;
}
};


// int main() {
//     string word1 = "abc";
//     string word2 = "pqr";
    
//     string merged = mergeAlternately(word1, word2);
    
//     cout << merged << endl;  // Output: "apbqcr"
    
//     return 0;
// }
