// Generate all subsequence and check 
// power set using bit manipulation/recursion
// No need to generate all subsequence
// Take and not take
// https://takeuforward.org/data-structure/subset-sum-equal-to-target-dp-14/

class Solution {
  public:
    bool helper(int index,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(index==0){
            return arr[0]==target;
        }
        
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        
        bool not_take=helper(index-1,target,arr,dp);
        bool take=false;
        if(arr[index]<=target){
            take=helper(index-1,target-arr[index],arr,dp);
        }
        return dp[index][target]=take||not_take;
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(n-1,target,arr,dp);
    }
};
