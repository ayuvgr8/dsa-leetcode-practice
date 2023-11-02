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
// class Solution {
// public:
//     int averageOfSubtree(TreeNode* root) {
        
//     }
// };


// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }

    pair<int, int> dfs(TreeNode* node, int& count) {
        if (!node) {
            return {0, 0};
        }

        // Recursively calculate the sum and count of the left and right subtrees
        pair<int, int> leftSubtree = dfs(node->left, count);
        pair<int, int> rightSubtree = dfs(node->right, count);

        // Calculate the sum and count of the current subtree
        int currentSum = leftSubtree.first + rightSubtree.first + node->val;
        int currentCount = leftSubtree.second + rightSubtree.second + 1;

        // Calculate the average of the current subtree
        int average = currentSum / currentCount;

        // Check if the current node's value is equal to the average of its subtree
        if (node->val == average) {
            count++;
        }

        return {currentSum, currentCount};
    }
};
