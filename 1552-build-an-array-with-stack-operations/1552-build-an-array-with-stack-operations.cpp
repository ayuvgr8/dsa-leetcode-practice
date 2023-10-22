class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations; // To store the operations

        int i = 0; // Pointer for the target array
        int num = 1; // The number in the range [1, n]

        while (i < target.size() && num <= n) {
            // If the current target element matches the number, perform a "Push" operation.
            if (target[i] == num) {
                operations.push_back("Push");
                i++;
            } else {
                // If they don't match, perform a "Push" followed by a "Pop" operation.
                operations.push_back("Push");
                operations.push_back("Pop");
            }
            num++; // Move to the next number
        }

        return operations;
    }
};
