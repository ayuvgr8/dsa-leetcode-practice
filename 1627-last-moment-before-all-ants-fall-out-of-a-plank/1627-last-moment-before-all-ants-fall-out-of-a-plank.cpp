class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int left_max = 0;
        int right_max = 0;

        for (int ant_pos : left) {
            left_max = max(left_max, ant_pos);
        }

        for (int ant_pos : right) {
            right_max = max(right_max, n - ant_pos);
        }

        return max(left_max, right_max);
    }
};

