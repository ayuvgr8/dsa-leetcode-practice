class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st; // Create a stack to store scores.

        for (string op : ops) {
            if (op == "C") {
                // If the operation is "C" (Cancel), remove the last valid score from the stack.
                st.pop();
            } else if (op == "D") {
                // If the operation is "D" (Double), double the last valid score and push it to the stack.
                int prev = st.top();
                st.push(prev * 2);
            } else if (op == "+") {
                // If the operation is "+", calculate the sum of the last two valid scores and push it to the stack.
                int prev1 = st.top();
                st.pop();
                int prev2 = st.top();
                int sum = prev1 + prev2;
                st.push(prev1);
                st.push(sum);
            } else {
                // If the operation is a number, convert it to an integer and push it to the stack.
                int score = stoi(op);
                st.push(score);
            }
        }

        int totalScore = 0;
        while (!st.empty()) {
            // Calculate the total sum of scores in the stack.
            totalScore += st.top();
            st.pop();
        }

        return totalScore;
    }
};
