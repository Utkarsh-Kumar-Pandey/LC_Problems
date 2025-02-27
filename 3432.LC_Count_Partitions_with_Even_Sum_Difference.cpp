// My approach
class Solution {
public:
    bool iseven(int n) {
        if (n % 2 == 0) {
            return true;
        }
        return false;
    }
    int countPartitions(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int pref_sum = 0;
        int count = 0;

        for (int j = 0; j < nums.size() - 1; j++) {
            pref_sum += nums[j];
            if (iseven(abs(pref_sum - (sum - pref_sum)))) {
                count++;
            }
        }
        return count;
    }
};
