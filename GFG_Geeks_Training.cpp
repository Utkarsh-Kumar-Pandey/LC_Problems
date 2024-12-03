// Approach is watching the previous last step {last}
// Finding the maximum of the task
// 3rd task would be denoting the last step that no task is performed right now
// Indexed from 0...3
class Solution {
public:
    int func(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) { 
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
        if (dp[day][last] != -1) {
            return dp[day][last];
        }
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int current = arr[day][task] + func(day - 1, task, arr, dp);
                maxi = max(maxi, current);
            }
        }
        return dp[day][last] = maxi;
    }

    int maximumPoints(vector<vector<int>>& arr, int n) {
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return func(n - 1, 3, arr, dp);
    }
};
