// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();
        if (n == 0) {
            return result;  // Return an empty result for an empty input.
        }

        int start = nums[0];  // Initialize the start of the current range.
        int end = nums[0];    // Initialize the end of the current range.

        for (int i = 1; i < n; ++i) {
            if (nums[i] == end + 1) {
                end = nums[i];  // Extend the current range.
            } else {
                if (start == end) {
                    result.push_back(to_string(start));  // Add "a" if it's a single element.
                } else {
                    result.push_back(to_string(start) + "->" + to_string(end));  // Add "a->b" if it's a range.
                }
                start = end = nums[i];  // Start a new range.
            }
        }

        // Add the last range or element.
        if (start == end) {
            result.push_back(to_string(start));
        } else {
            result.push_back(to_string(start) + "->" + to_string(end));
        }

        return result;
    }
};

// int main() {
//     Solution solution;
//     vector<int> nums = {0, 1, 2, 4, 5, 7};
//     vector<string> result = solution.summaryRanges(nums);
    
//     cout << "The smallest sorted list of ranges is: ";
//     for (const string& range : result) {
//         cout << range << " ";
//     }
//     cout << endl;
    
//     return 0;
// }
