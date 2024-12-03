// Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } 
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
// Memoization taking a recursive stack space

class Solution {
public:
int helper(int findex,int sindex,int m,int n,vector<vector<int>>&dp){
    if(findex==0 and sindex==0){
        return 1;
    }
    if(findex<0 ||sindex<0){
        return 0;
    }
    if(dp[findex][sindex]!=-1){
        return dp[findex][sindex];
    }
    int up=helper(findex-1,sindex,m,n,dp);
    int left=helper(findex,sindex-1,m,n,dp);
    return dp[findex][sindex]=up+left;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(m-1,n-1,m,n,dp);
    }
};*/

/*
class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n,1);

        for(int i = 1 ; i < m; i++){
            int prev = 1;
            for(int j = 1; j < n; j++){
                dp[j] += prev;
                prev = dp[j];
            }
        }

        return dp[n-1];
    }
};
*/
