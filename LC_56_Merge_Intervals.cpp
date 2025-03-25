class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // We will also sort the intervals before
        sort(intervals.begin(), intervals.end());
        // Storing out merged part in this
        vector<vector<int>> ans;
        for (auto it : intervals) {
            // If overlapping intervals not present
            // If no element present
            // Next element start is greater than the end of previous
            if (ans.size() == 0 || ans.back()[1] < it[0]) {
                ans.push_back(it);
            } 
            else {
                ans.back()[1] = max(ans.back()[1], it[1]);
            }
        }
        return ans;
    }
};
