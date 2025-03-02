class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int ans = 0;
        int count0 = 0;
        for (int i = 0; i < n; i++) {
            int count1 = 0;
            if (s[i] == '0') {
                count0++;
            }
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '1') {
                    count1++;
                }
                ans = max(ans, count0 + count1);
            }
        }
        return ans;
    }
};
