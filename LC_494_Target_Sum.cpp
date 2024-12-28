// For Each of them we will have a choice to either add the element or subtract the element.
class Solution {
public:
    int backtrack(int index, int curr_sum, int target, vector<int>& nums) {
        if (index == nums.size()) {
            // Agar aakhri tak aagya h to sum check karo equal to target hai ki nahi
            if (curr_sum == target) {
                return 1;
            } else {
                return 0;
            }
        }
        return backtrack(index + 1, curr_sum + nums[index], target, nums) +
               backtrack(index + 1, curr_sum - nums[index], target, nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // Initially both values kept as 0;
        int n = nums.size();
        int index = 0;
        int curr_sum = 0;
        return backtrack(index, curr_sum, target, nums);
    }
};
