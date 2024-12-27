class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int ans = 0;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {

            return duration;
        }
        for (int i = 1; i < n; i++) {
            if (timeSeries[i] <= timeSeries[i - 1] + duration - 1) {
                ans += timeSeries[i] - timeSeries[i - 1];
            } else {
                ans += duration;
            }
        }

        ans += duration;
        return ans;
    }
};
