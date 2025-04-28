class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left = 0;
        long long sum = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum * (i - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }
            ans += (i - left + 1);
        }
        return ans;
    }
};
