class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(int j=1;j<=n;j++){
            if(mpp.find(j)==mpp.end()){
                ans.push_back(j);
            }
        }
        return ans;
    }
};
