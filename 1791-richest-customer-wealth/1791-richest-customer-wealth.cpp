class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int richestWealth = 0;  // Initialize a variable to store the richest customer's wealth
        
        // Iterate through each customer's account
        for (int i = 0; i < accounts.size(); i++) {
            int customerWealth = 0;  // Initialize the wealth for the current customer
            
            // Iterate through each bank account for the current customer
            for (int j = 0; j < accounts[i].size(); j++) {
                customerWealth += accounts[i][j];  // Add the money in the bank account to the customer's wealth
            }
            
            // Update the richest wealth if the current customer's wealth is greater
            richestWealth = max(richestWealth, customerWealth);
        }
        
        return richestWealth;  // Return the wealth of the richest customer
    }
};
// Save to grepper
// Here's how the code works:

// We declare a maximumWealth variable to store the wealth of the richest customer and initialize it to 0.

// We iterate through each customer's account using a for loop with an index variable i.

// Inside the loop, we initialize a customerWealth variable to 0, which will store the wealth of the current customer.

// We iterate through each bank account of the current customer using another for loop with an index variable j.

// For each bank account, we add the amount of money in that account to the customerWealth.

// After processing all the bank accounts for the current customer, we update the richestWealth by taking the maximum of the current richestWealth and the customerWealth. This step ensures that we keep track of the wealthiest customer as we iterate through all customers.

// Finally, we return the richestWealth, which contains the wealth of the richest customer after processing all customers.

// This solution calculates the wealth of each customer by summing the money in their bank accounts and keeps track of the richest customer. It has a time complexity of O(m * n), where m is the number of customers, and n is the number of bank accounts.





