class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) {
            return s; // No conversion needed in these cases.
        }
        
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool goingDown = false;
        
        for (char c : s) {
            rows[curRow] += c; // Append the character to the current row.
            
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown; // Change direction when reaching the top or bottom rows.
            }
            
            curRow += goingDown ? 1 : -1; // Update the row number accordingly.
        }
        
        string result;
        for (string row : rows) {
            result += row; // Concatenate all rows to get the final result.
        }
        
        return result;
    }
};
