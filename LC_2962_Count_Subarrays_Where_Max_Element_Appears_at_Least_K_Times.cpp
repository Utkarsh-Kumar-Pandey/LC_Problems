class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long maxi = *max_element(nums.begin(), nums.end());
        int left = 0;
        int count = 0;
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == maxi) {
                count++;
            }
            while (count >= k) {
                if (nums[left] == maxi) {
                    count--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
};

