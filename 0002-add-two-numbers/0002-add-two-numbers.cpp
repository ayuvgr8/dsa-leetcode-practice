/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
//     }
// };

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0); // Create a dummy node to serve as the starting point of the result linked list.
        ListNode* current = &dummy; // Initialize a current pointer.

        int carry = 0; // Initialize carry to 0.

        while (l1 || l2) {
            int x = l1 ? l1->val : 0; // If l1 is not nullptr, get its value; otherwise, use 0.
            int y = l2 ? l2->val : 0; // If l2 is not nullptr, get its value; otherwise, use 0.

            int sum = x + y + carry; // Calculate the sum of values from l1, l2, and the carry.

            carry = sum / 10; // Update the carry for the next iteration.
            sum %= 10; // Calculate the digit to be added to the result.

            current->next = new ListNode(sum); // Create a new node for the result with the calculated digit.
            current = current->next; // Move the current pointer to the next node.

            if (l1) l1 = l1->next; // Move to the next node in l1 if it's not nullptr.
            if (l2) l2 = l2->next; // Move to the next node in l2 if it's not nullptr.
        }

        if (carry > 0) {
            current->next = new ListNode(carry); // If there's a remaining carry, add it as a new node.
        }

        return dummy.next; // Return the next node of the dummy, which is the head of the result linked list.
    }
};
