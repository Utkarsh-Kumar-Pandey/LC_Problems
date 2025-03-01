class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n - 1) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
                i += 2;

            } 
            else {
                i++;
            }
        }
        vector<int> ans;
        int il = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[il], nums[j]);
                il++;
            }
        }

        return nums;
    }
};
