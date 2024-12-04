class Solution {
public:
    int helper(vector<vector<int>>& dp, int m, int n,vector<vector<int>>& obstacleGrid) {
        // m>0 && n>0 and obstaclegrid me koi bhi obstacle na ho to work karenge
        if (m < 0 || n < 0 || obstacleGrid[m][n] == 1) {
            return 0;
        }
        if (m == 0 && n == 0) {
            return 1;
        }
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        int up = helper(dp, m - 1, n, obstacleGrid);
        int left = helper(dp, m, n - 1, obstacleGrid);
        return dp[m][n] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();    // Row
        int n = obstacleGrid[0].size(); // Col

        // A dp array {2D}
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans=helper(dp, m - 1, n - 1, obstacleGrid);
        return ans;
    }
};
