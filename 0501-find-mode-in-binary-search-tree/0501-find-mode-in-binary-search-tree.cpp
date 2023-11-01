/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result; // To store the modes
        int currentVal = 0; // Initialize the current value to an arbitrary number
        int currentCount = 0; // Initialize the current count
        int maxCount = 0; // Initialize the maximum count

        // In-order traversal using a stack
        stack<TreeNode*> st;
        TreeNode* currentNode = root;

        while (currentNode || !st.empty()) {
            // Go to the leftmost node
            while (currentNode) {
                st.push(currentNode);
                currentNode = currentNode->left;
            }

            // Process the current node
            currentNode = st.top();
            st.pop();

            if (currentNode->val == currentVal) {
                currentCount++;
            } else {
                currentVal = currentNode->val;
                currentCount = 1;
            }

            // Check if the current count is greater than the maximum count
            if (currentCount > maxCount) {
                maxCount = currentCount;
                result.clear(); // Clear previous modes
                result.push_back(currentVal); // Add the new mode
            } else if (currentCount == maxCount) {
                result.push_back(currentVal); // Add another mode with the same count
            }

            // Move to the right subtree
            currentNode = currentNode->right;
        }

        return result;
    }
};
