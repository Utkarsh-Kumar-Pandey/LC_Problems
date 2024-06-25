//My solution 
//Find sum at every position then finding maximum length

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxlength = INT_MIN;
        int sum = 0;
        for (auto it : nums) {
            sum += it;
            maxlength = max(maxlength, sum);

            if (sum < 0) {
                sum = 0;
            }
        }
        return maxlength;
    }
};
