// Optimal solution
// Watched TUF's Solution 
// https://www.youtube.com/watch?v=_eNhaDCr6P0
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int length = 0;
        int maxlength = 0;
        int max_freq_ele = 0;
        vector<int> check(26, 0);
        // 0 is the initialisez for counting the occurence of elements

        for (int right = 0; right < n; right++) {
            // Count characters
            check[s[right] - 'A']++;
            max_freq_ele = max(max_freq_ele, check[s[right] - 'A']);

            int substring_length = right - left + 1;
            if (substring_length - max_freq_ele > k) {
                check[s[left] - 'A']--;
                left++;
            }

            maxlength = max(maxlength, right - left + 1);
        }
        return maxlength;
    }
};
