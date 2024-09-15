//My approach
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        // Traversing the subarray
        for(int i=0;i<n;i++){
            int maxi=nums[i];
            int mini=nums[i];
            for(int j=i;j<n;j++){
                maxi=max(maxi,nums[j]);
                mini=min(mini,nums[j]);
                sum+=maxi-mini;
            }
        }
        return sum;
    }
};