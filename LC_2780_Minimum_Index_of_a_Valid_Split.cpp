class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        unordered_map<int, int> mpp2;
        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;
        }
        // Now I will check the count of the first part and accordingly will get for the second part
        for (int j = 0; j < n; j++) {
            int first_size = j + 1;
            mpp[nums[j]]--;
            mpp2[nums[j]]++;
            if (mpp[nums[j]] != 0 && mpp[nums[j]] > (n - first_size) / 2 &&mpp2[nums[j]] > (first_size / 2)) {
                return first_size - 1;
            }
        }
        return -1;
    }
};
