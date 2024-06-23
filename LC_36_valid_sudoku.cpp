//Implementation after watching Nick White's solution
// https://www.youtube.com/watch?v=Pl7mMcBm2b8

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> valStore;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char currentVal = board[i][j];

                // if the cell is filled
                if (currentVal != '.') {

                    // Store the values coming up
                    string row = "row" + to_string(i) + currentVal;
                    string col = "col" + to_string(j) + currentVal;
                    string box = "subbox" + to_string(i / 3) + to_string(j / 3) + currentVal;

                    if (!valStore.insert(row).second ||
                        !valStore.insert(col).second ||
                        !valStore.insert(box).second) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// This can be solved by using Recursion 
// Documentaion :- https://takeuforward.org/data-structure/sudoku-solver/
