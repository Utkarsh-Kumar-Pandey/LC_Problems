class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> minrow;
        vector<int> maxcol;
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++) {
            int mini = INT_MAX;
            for (int j = 0; j < col; j++) {
                if (mini > matrix[i][j]) {
                    mini = matrix[i][j];
                }
            }
            minrow.push_back(mini);
        }
        for (int j = 0; j < col; j++) {
            int maxi = INT_MIN;
            for (int i = 0; i < row; i++) {
                if (maxi < matrix[i][j]) {
                    maxi = matrix[i][j];
                }
            }
            maxcol.push_back(maxi);
        }

        sort(minrow.begin(), minrow.end());
        sort(maxcol.begin(), maxcol.end());

        vector<int> res;
        for (int i = 0; i < minrow.size(); i++) {
            for (int j = 0; j < maxcol.size(); j++) {
                if (minrow[i] == maxcol[j]) {
                    res.push_back(minrow[i]);
                }
            }
        }
        return res;
    }
};
