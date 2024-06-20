class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.insert(nums[i]);
        }
        return ans.size()!=nums.size();

    }
};
