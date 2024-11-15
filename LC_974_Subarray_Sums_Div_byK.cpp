class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        int count=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        // kept the 0 in map initially
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int pre_div=sum%k;
            if(pre_div<0){
                pre_div+=k;
            }
            if(mpp.find(pre_div)!=mpp.end()){
                count+=mpp[pre_div];
            }

            mpp[pre_div]++;
        }
        return count;
        
    }
};
