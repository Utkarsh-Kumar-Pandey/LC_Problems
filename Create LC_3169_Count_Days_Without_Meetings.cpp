class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // First intution is O(n^2)
        // Second is merging out intervals then counting through map
        int count = 0;
        unordered_map<int, int> ans;
        vector<vector<int>> merge;
        sort(meetings.begin(), meetings.end());
        for (auto it : meetings) {
            // No overlapping
            if (merge.size() == 0 || merge.back()[1] < it[0]) {
                merge.push_back(it);
            } 
            else {
                merge.back()[1] = max(merge.back()[1], it[1]);
            }
        }
        int x = merge.size() - 1;
        count += merge[0][0] - 1;
        if (merge[x][1] < days) {
            count += days - merge[x][1];
        }
        for (int i = 1; i < merge.size(); i++) {
            count += merge[i][0] - merge[i - 1][1] - 1;
        }
        return count;
    }
};
