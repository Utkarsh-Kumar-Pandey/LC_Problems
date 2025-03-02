class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                mpp[nums[i]]++;
            }
        }
        int maxi = INT_MIN;
        int ele;

        for (auto it : mpp) {
            // The or part inside the condition is checking out that there is
            // repetition of number of times maximum element has appeared and we
            // find the smallest ones from that
            if (maxi < it.second || (it.second == maxi && it.first < ele)) {
                maxi = max(it.second, maxi);
                ele = it.first;
            }
        }
        if (maxi == INT_MIN) {
            return -1;
        }
        return ele;
    }
};
