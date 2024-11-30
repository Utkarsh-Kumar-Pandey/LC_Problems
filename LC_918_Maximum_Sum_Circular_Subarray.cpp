// Approached with kadane's Algo 
// Found the maxsum subarray and minsum subarray 
// returned max of the total-minsum ->[for circular format] and maxsum,
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxAns = INT_MIN, minAns = INT_MAX;
        int maxSum = 0, minSum = 0, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxSum = max(maxSum, 0) + nums[i];
            maxAns = max(maxAns, maxSum);
            minSum = min(minSum, 0) + nums[i];
            minAns = min(minAns, minSum);

            sum += nums[i];
        }
        if (maxAns > 0) {
            return max(maxAns, sum - minAns);
        } else {
            return maxAns;
        }
    }
};
