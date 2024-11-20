// Watched the solution
// https://www.youtube.com/watch?v=qyfekrNni90
class Solution {
public:
    int func(int hours, vector<int> piles) {
        int tot_time = 0;
        for (int i = 0; i < piles.size(); i++) {
            tot_time += (piles[i] + hours - 1) / hours;
        }
        return tot_time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (maxi < piles[i]) {
                maxi = piles[i];
            }
        }
        int low = 1;
        int high = maxi;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int req_time = func(mid, piles);
            if (req_time <= h) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
