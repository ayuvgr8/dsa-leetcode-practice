class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = __builtin_popcount(a); // Count the number of 1 bits in binary representation of a
            int countB = __builtin_popcount(b); // Count the number of 1 bits in binary representation of b
            if (countA == countB) {
                return a < b; // If they have the same number of 1 bits, sort them in ascending order.
            }
            return countA < countB; // Otherwise, sort by the number of 1 bits.
        });
        return arr;
    }
};
