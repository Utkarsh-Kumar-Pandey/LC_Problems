// Tabulation approach
class Solution { 
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n,0);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int first=dp[i-1]+abs(height[i]-height[i-1]);
            int second=INT_MAX;
            if(i>1){
                second=dp[i-2]+abs(height[i]-height[i-2]);
            }
            dp[i]=min(first,second);
        }
        return dp[n-1];
    }
};
/*
Memoization

class Solution {
  public:
  int func(vector<int>&height,int n,vector<int>&dp){
      if(n==0){
          return 0;
      }
      if(dp[n]!=-1){
          return dp[n];
      }
      int left=func(height,n-1,dp)+abs(height[n]-height[n-1]);
      int right=INT_MAX;
      if(n>1){
          right=func(height,n-2,dp)+abs(height[n]-height[n-2]);
      }
      return dp[n]=min(left,right);
  }
    int minimumEnergy(vector<int>& height, int n) {
        vector<int>dp(n+1,-1);
        return func(height,n-1,dp);
    }
};*/
/*
Recursive solution 

class Solution {
  public:
  int func(vector<int>&height,int n){
      if(n==0){
          return 0;
      }
      int left=func(height,n-1)+abs(height[n]-height[n-1]);
      int right=INT_MAX;
      if(n>1){
          right=func(height,n-2)+abs(height[n]-height[n-2]);
      }
      return min(left,right);
  }
    int minimumEnergy(vector<int>& height, int n) {
        return func(height,n-1);
    }
};*/
