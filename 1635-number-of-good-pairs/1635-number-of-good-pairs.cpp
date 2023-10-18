class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> count;  // Create a map to store the count of each number
        int goodPairs = 0;  // Initialize the count of good pairs
        
        for (int num : nums) {
            if (count.find(num) != count.end()) {
                // If we've seen this number before, increment the count of good pairs
                goodPairs += count[num];
            }
            // Increment the count of the current number in the map
            count[num]++;
        }
        
        return goodPairs;
    }
};
