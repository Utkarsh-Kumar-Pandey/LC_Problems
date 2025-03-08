class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
      // Was approaching initially likewise for calculating out the prefix and suffix array 
        // Caluclating the prefix and suffic array O(n^2)
        // for(int i=0;i<nums.size();i++){
        //     for(int j=0;j<i;j++){
        //         prefix[i]*=nums[j];
        //     }
        //     for(int k=i+1;k<nums.size();k++){
        //         suffix[i]*=nums[k];
        //     }
        // }
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }
        for (int j = n - 2; j >= 0; j--) {
            suffix[j] = nums[j + 1] * suffix[j + 1];
        }
        for (int l = 0; l < nums.size(); l++) {
            ans.push_back(prefix[l] * suffix[l]);
        }
        return ans;
    }
};
