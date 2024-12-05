// Tabulation Approach
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(triangle);
        // Since the base case to stop would be the last row, so we will do the calculation from second last row
        for(int row=n-2;row>=0;row--){

            for(int col=0;col<triangle[row].size();col++){
                dp[row][col]+=min((dp[row+1][col]),(dp[row+1][col+1]));
            }
        }
        return dp[0][0];
        
    }
};
/*
// Memoization Approach
class Solution {
public:
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int row,int col) {
        if (row == triangle.size() - 1) {
            return triangle[row][col];
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        int down = helper(triangle, dp, row + 1, col);
        int diagonal = helper(triangle, dp, row + 1, col + 1);
        return dp[row][col] = triangle[row][col] + min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<vector<int>> dp(row, vector<int>(row, -1));
        return helper(triangle, dp, 0, 0);
    }
};*/
