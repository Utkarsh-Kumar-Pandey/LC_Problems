class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>ans;
        for(auto it:nums){
            ans[it]++;
        }
        for(auto it:ans){
            if(it.second>1){
                return it.first;
            }
        }
        return -1;
        
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};
