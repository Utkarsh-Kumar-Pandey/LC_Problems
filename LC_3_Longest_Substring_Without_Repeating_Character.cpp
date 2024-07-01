// Brute Force Approach 
// T.C - O(n²) 
// Storing each occurence in hashmap and if it re-occur,find the length 
    class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlength = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mpp;
            int length = 0;
            for (int j = i; j < n; j++) {
                if (mpp.find(s[j]) != mpp.end()) {
                    break;
                }
                length = j - i + 1;
                maxlength = max(maxlength, length);
                mpp[s[j]] = 1;
            }
        }
        return maxlength;
    }
};

// Optimization
// T.C - O(n)
// To have an Optimized approach for substring [think about two pointers and sliding window approach]
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> check(256, -1);
        int left = 0;
        int right = 0;
        int maxlength = 0;
        int length = 0;
        for (int right = left; right < s.size(); right++) {
            if (check[s[right]] != -1) {
                // Check the index is after the left pointer
                if (check[s[right]] >= left) {
                    left = check[s[right]] + 1;
                }
            }
            length = right - left + 1;
            maxlength = max(maxlength, length);
            check[s[right]] = right;

            // check stores the current index
        }
        return maxlength;
    }
};