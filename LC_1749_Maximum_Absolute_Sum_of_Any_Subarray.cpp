// My first approach
/* class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int prefixsum = 0;
            for (int j = i; j < n; j++) {
                prefixsum+=nums[j];
                ans=max(abs(prefixsum),ans);
            }
        }
        return ans;
    }
};
*/

// would approach this using kadane's algo now
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxpos = INT_MIN;
        int maxneg = INT_MIN;

        int sump = 0;
        int sumn = 0;

        for (int i = 0; i < nums.size(); i++) {
            sump += nums[i];
            sumn += nums[i];
            maxpos = max(maxpos, sump);
            maxneg = max(maxneg, -sumn);
            if (sump < 0) {
                sump = 0;
            }
            if (sumn > 0) {
                sumn = 0;
            }
        }
        return max(maxpos, maxneg);
    }
};

