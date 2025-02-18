class Solution {
public:
    int coin(int i, vector<int>& coins, int amount, vector<vector<int>>& dp) {
        if (amount == 0)
            return 0;
        if (i < 0){

            return 1e9;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int nottake = coin(i - 1, coins, amount, dp);
        int take = 1e9;
        if (coins[i] <= amount) {
            take = 1 + coin(i, coins, amount - coins[i], dp);
        }

        return dp[i][amount]=min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int x = coin(n - 1, coins, amount,dp);
        if (x == 1e9) {
            return -1;
        }
        return x;
    }
};
