class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> final;
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int n = nums.size();
        int i = 0;
        while (i <= n - 3) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                i++;
                continue;
            }
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if (nums[i] == -(nums[j] + nums[k]) && j != k) {
                    ans.push_back(nums[i]);
                    ans.push_back(nums[j]);
                    ans.push_back(nums[k]);
                    final.push_back(ans);
                    ans.clear();
                    while (k > 0 && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    while (j < n - 1 && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                    k--;
                } else if (nums[j] + nums[k] > -(nums[i])) {

                    k--;
                } else {
                    j++;
                }
            }
            i++;
        }
        return final;
    }
};