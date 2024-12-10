// Approaching this question 
// We know that the subset sum has to be total sum/2 ,S=s1+s2;
// iF Total sum hi odd aajaega to Not possible 
// Subset sum=S/2 same approach subset sum equals target

class Solution {
public:
bool subset_sum_target(int n,int target,vector<int>&nums){
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));

    // Base cases 
    // If target becomes zero we stop
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }

    // First element only matches if it is target itself
    if(nums[0]<=target){
        dp[0][nums[0]]=true;
    }

    // Bottom-Up appraoch
    for(int i=1;i<n;i++){
        for(int j=0;j<=target;j++){
            bool Not_take=dp[i-1][j];

            bool Take=false;
            if(nums[i]<=j){
                Take=dp[i-1][j-nums[i]];
            }
            dp[i][j]=Take||Not_take;
        }
    }
    return dp[n-1][target];

}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2){
            return false; 
        }
        return subset_sum_target(n,sum/2,nums);
        
        
    }
};
