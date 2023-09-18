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
#include <iostream>
using namespace std;

// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: If the root is NULL, return false because there's no path.
        if (root == NULL) {
            return false;
        }

        // Subtract the current node's value from the targetSum.
        targetSum -= root->val;

        // Check if we have reached a leaf node and the remaining targetSum is 0.
        if (root->left == NULL && root->right == NULL) {
            return targetSum == 0;
        }

        // Recursively check the left and right subtrees.
        bool leftResult = hasPathSum(root->left, targetSum);
        bool rightResult = hasPathSum(root->right, targetSum);

        // Return true if either the left or right subtree has a valid path sum.
        return leftResult || rightResult;
    }
};

// int main() {
//     // Construct the example tree
//     TreeNode* root = new TreeNode(5);
//     root->left = new TreeNode(4);
//     root->right = new TreeNode(8);
//     root->left->left = new TreeNode(11);
//     root->left->left->left = new TreeNode(7);
//     root->left->left->right = new TreeNode(2);
//     root->right->left = new TreeNode(13);
//     root->right->right = new TreeNode(4);
//     root->right->right->right = new TreeNode(1);

//     int targetSum = 22;

//     Solution solution;
//     bool result = solution.hasPathSum(root, targetSum);

//     if (result) {
//         cout << "The tree has a path with the target sum." << endl;
//     } else {
//         cout << "No path with the target sum found in the tree." << endl;
//     }

//     return 0;
// }
