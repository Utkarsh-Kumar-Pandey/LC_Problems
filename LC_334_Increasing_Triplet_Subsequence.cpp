class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        int third = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] <= first) {
                first = nums[i];
            } 
            else if (nums[i] <= second) {
                second = nums[i];
            } 
            else {
                third = nums[i];
                // why directly return?
                // [4,5,2147483647,1,2] this can ruin it
                return true;
            }
        }
        return third != INT_MAX;
    }
};
