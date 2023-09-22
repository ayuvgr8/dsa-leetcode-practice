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
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
        
//     }
// };

// #include <iostream>
// #include <vector>

// using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Check if the input vector is empty
        if (nums.empty()) {
            return nullptr;
        }

        // Call a helper function to construct the balanced BST
        return constructBST(nums, 0, nums.size() - 1);
    }

    TreeNode* constructBST(vector<int>& nums, int left, int right) {
        // Base case: If the left index is greater than the right index, return nullptr
        if (left > right) {
            return nullptr;
        }

        // Calculate the middle index to create a balanced BST
        int mid = left + (right - left) / 2;

        // Create a new TreeNode with the middle element as the value
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively construct the left and right subtrees
        root->left = constructBST(nums, left, mid - 1);
        root->right = constructBST(nums, mid + 1, right);

        return root;
    }
};

// Helper function to print the binary tree in-order for verification
void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->val << " ";
        inOrderTraversal(root->right);
    }
}

// int main() {
//     Solution solution;
    
//     // Test case 1
//     vector<int> nums1 = {-10, -3, 0, 5, 9};
//     TreeNode* root1 = solution.sortedArrayToBST(nums1);
//     cout << "Test case 1: ";
//     inOrderTraversal(root1); // Expected output: -10 -3 0 5 9
//     cout << endl;

//     // Test case 2
//     vector<int> nums2 = {1, 3};
//     TreeNode* root2 = solution.sortedArrayToBST(nums2);
//     cout << "Test case 2: ";
//     inOrderTraversal(root2); // Expected output: 1 3
//     cout << endl;

//     return 0;
// }
