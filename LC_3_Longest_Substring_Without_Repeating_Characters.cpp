// My Approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int maxi = INT_MIN;
        int ans = 0;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mpp.find(s[i]) != mpp.end()) {
                while (mpp.find(s[i]) != mpp.end()) {
                    mpp.erase(s[j]);
                    j++;
                }
            }
            ans = i - j + 1;
            maxi = max(maxi, ans);
            mpp[s[i]] = i;
        }
        if (maxi == INT_MIN) {
            return 0;
        }
        return maxi;
    }
};
