class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long sum=0;
        int n=nums.size();
        int st=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mpp[nums[i]]++;
            // Removing the sum of prev 
            while(mpp[nums[i]]>1){
                mpp[nums[st]]--;
                sum-=nums[st];
                st++;
            }
            if(i-st==k-1){
                ans=max(ans,sum);
                sum-=nums[st];
                mpp[nums[st]]--;
                st++;
            }
        }
        return ans;
        
    }
};
