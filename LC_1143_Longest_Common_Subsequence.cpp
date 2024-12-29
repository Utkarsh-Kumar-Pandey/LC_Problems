class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i=n;
        int j=m;
        string lcs="";
        while(i>0 &&j>0){
            if(text1[i-1]==text2[j-1]){
                lcs+=text1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
        reverse(lcs.begin(),lcs.end());
        cout<<lcs;
        return lcs.size();
        
    }
};
//-----------------------------------------------------------------
class Solution {
public:
    int helper(int n, int m, string& text1, string& text2,
               vector<vector<int>>& dp) {
        if (n < 0 || m < 0) {
            return 0;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        if (text1[n] == text2[m]) {
            return dp[n][m] = 1 + helper(n - 1, m - 1, text1, text2, dp);

        } else {
            return dp[n][m] = max(helper(n - 1, m, text1, text2, dp),
                                  helper(n, m - 1, text1, text2, dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return helper(n - 1, m - 1, text1, text2, dp);
    }
};
//------------------------------------------------------------
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // A bottom up tabulation approach used here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i-1] == text2[j-1]) {
                    // The letters match
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        if (dp[n][m] == -1) {

            return 0;
        }
        return dp[n][m];
    }
};
