class Solution {
public:
    int helper(vector<vector<int>>& dp, int m, int n,vector<vector<int>>& grid) {
        if(m==0 &&n==0){
            return grid[0][0];
        }
        if(m<0 ||n<0){
            return INT_MAX;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int up=helper(dp,m-1,n,grid);
        int left=helper(dp,m,n-1,grid);
        
        // storing the minimum value among the above and the left value
        dp[m][n]=grid[m][n]+min(up,left);
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = helper(dp, m-1, n-1, grid);
        return ans;
    }
};
