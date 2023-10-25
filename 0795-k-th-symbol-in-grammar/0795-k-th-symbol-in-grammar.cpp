class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case: when n = 1, there's only one element in the first row (0).
        if (n == 1) {
            return 0;
        }
        
        // Calculate the length of the previous row.
        int prevLen = pow(2, n - 2);
        
        // If k is in the first half of the current row, it's the same as k in the previous row.
        if (k <= prevLen) {
            return kthGrammar(n - 1, k);
        } else {
            // If k is in the second half of the current row, it's the complement of k in the previous row.
            return 1 - kthGrammar(n - 1, k - prevLen);
        }
    }
};
