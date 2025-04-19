// My unique approach
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        unordered_map<char, int> mpp;
        for (auto it : s1) {
            mpp[it]++;
        }
        int left = 0;
        unordered_map<char, int> window_mpp;
        for (int i = 0; i < s2.size(); i++) {
            window_mpp[s2[i]]++;
            if (i - left + 1 == s1.size()) {
                if (mpp == window_mpp) {
                    return true;
                    break;
                }
            }
            // When the fixed window size exceeds then we slide the window
            if (i - left + 1 > s1.size()) {
                window_mpp[s2[left]]--;
                if (window_mpp[s2[left]] == 0) {
                    window_mpp.erase(s2[left]);
                }
                left++;
                if (mpp == window_mpp) {
                    return true;
                    break;
                }
            }
        }
        return false;
    }
};


