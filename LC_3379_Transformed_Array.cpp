class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                int x = (i + nums[i]) % n;
                ans[i] = nums[x];
            } else if (nums[i] < 0) {
                int shift = i + nums[i] % n + n;
                int shifted = (shift) % n;
                // int place = nums[shifted] % nums.size();
                ans[i] = nums[shifted];
            } else {
                ans[i] = nums[i];
            }
        }

        return ans;
    }
};
