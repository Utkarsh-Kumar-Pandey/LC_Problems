class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi = INT_MIN;
        vector<bool> ans;
        for (int i = 0; i < candies.size(); i++) {
            maxi = max(maxi, candies[i]);
        }
        for (int j = 0; j < candies.size(); j++) {
            if (candies[j] + extraCandies >= maxi) {
                ans.push_back(true);
                continue;
            }
            ans.push_back(false);
        }
        return ans;
    }
};
