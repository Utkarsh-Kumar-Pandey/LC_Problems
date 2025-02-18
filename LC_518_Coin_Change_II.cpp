class Solution {
public:
int funct(int index,int amount,vector<int>coins,int n,vector<vector<int>>&dp){
    int take=0;
    int nottake=0;
    if(amount==0){
        return 1;
    }
    if(index==n){
        return 0;
    }
    if(dp[index][amount]!=-1){
        return dp[index][amount];
    }
    if(amount>=coins[index]){
        take=funct(index,amount-coins[index],coins,n,dp);
    }
    nottake=funct(index+1,amount,coins,n,dp);
    return dp[index][amount]=nottake+take;
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return funct(0,amount,coins,n,dp);
        
    }
};
