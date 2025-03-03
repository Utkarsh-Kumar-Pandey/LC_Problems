class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans;
        vector<int> ans2;
        int piv = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) {
                ans.push_back(nums[i]);
            } else if (nums[i] > pivot) {
                ans2.push_back(nums[i]);
            } else {
                piv++;
            }
        }
        
        while (piv > 0) {
            ans.push_back(pivot);
            piv--;
        }

        for (auto it : ans2) {
            ans.push_back(it);
        }
        return ans;
    }
};
