class Solution {
public:
    bool isodd(int n) {
        if (n % 2 == 0) {
            return false;
        }
        return true;
    }
    bool iseven(int n) {
        if (n % 2 == 0) {
            return true;
        }
        return false;
    }
    bool isArraySpecial(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            // I'm Checking out the pairs one by one if odd|odd or even|even found then false
            if ((isodd(nums[i]) && isodd(nums[i + 1])) ||
                iseven(nums[i]) && iseven(nums[i + 1])) {
                return false;
            }
        }
        return true;
    }
};
