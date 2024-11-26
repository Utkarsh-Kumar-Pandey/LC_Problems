class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int ans = INT_MAX;
        int st = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            // Slide the window to the right if the sum persists to be greater than the target
            while (sum >= target) {
                ans = min(ans, i - st + 1);
                sum -= nums[st];
                st++;
            }
        }
        if (ans != INT_MAX) {
            return ans;
        }
        else{
            return 0;
        }
    }
};
