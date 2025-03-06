class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int ele = row * col;
        unordered_map<int, int> mpp;
        vector<int> ans;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                mpp[grid[i][j]]++;
            }
        }
        for (auto it : mpp) {
            if (it.second >= 2) {
                ans.push_back(it.first);
            }
        }
        for (int i = 1; i <= ele; i++) {
            if (mpp.find(i) == mpp.end()) {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};
