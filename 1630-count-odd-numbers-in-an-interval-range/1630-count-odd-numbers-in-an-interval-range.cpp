class Solution {
public:
    int countOdds(int low, int high) {
        if (low % 2 == 0 && high % 2 == 0) {
            // Both low and high are even, so there are (high - low) / 2 odd numbers.
            return (high - low) / 2;
        } else {
            // Either low or high is odd, so there are (high - low) / 2 + 1 odd numbers.
            return (high - low) / 2 + 1;
        }
    }
};
