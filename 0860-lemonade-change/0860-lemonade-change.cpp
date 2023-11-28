// class Solution {
// public:
//     bool lemonadeChange(vector<int>& bills) {
        
//     }
// };
// #include <unordered_map>
// #include <vector>

class Solution {
public:
    bool lemonadeChange(std::vector<int>& bills) {
        // Create a map to store the count of each bill denomination available
        std::unordered_map<int, int> availableChange;

        // Loop through each customer's payment
        for (int bill : bills) {
            if (bill == 5) {
                // If the customer pays with a $5 bill, increment the count of $5 bills
                availableChange[5]++;
            } else if (bill == 10) {
                // If the customer pays with a $10 bill, decrement the count of $5 bills
                // and increment the count of $10 bills
                if (availableChange[5] <= 0) {
                    // If there are no $5 bills available to provide change, return false
                    return false;
                }
                availableChange[5]--;
                availableChange[10]++;
            } else if (bill == 20) {
                // If the customer pays with a $20 bill
                if (availableChange[10] > 0 && availableChange[5] > 0) {
                    // If there are both $10 and $5 bills available, provide change using those
                    availableChange[10]--;
                    availableChange[5]--;
                } else if (availableChange[5] >= 3) {
                    // If there are at least three $5 bills available, provide change using them
                    availableChange[5] -= 3;
                } else {
                    // If no suitable combination of bills is available, return false
                    return false;
                }
            }
        }

        // All customers received correct change, return true
        return true;
    }
};
