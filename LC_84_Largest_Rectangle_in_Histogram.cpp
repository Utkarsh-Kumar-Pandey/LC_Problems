// MY FIRST APPROACH
// 29/99 TEST CASES
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1) {
            return heights[0];
        }
        int j = 0;
        int mini = heights[0];
        int maxi = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            int mini = heights[i];
            j = i + 1;
            mini = min(mini, heights[j]);
            int ans = mini * 2;
            if (heights[i] == 0) {
                mini = heights[j];
                ans = mini;
            }
            if (heights[j] == 0) {
                mini = heights[i];
                ans = mini;
            }

            maxi = max(maxi, ans);
        }
        return maxi;
    }
};
/*
Solved for this case by applying when the current traversed value is 0
Input
heights =[0,9,1,2]
Output 2
Expected 9

*/
// --FAILED THE APPROACH HERE--
/*
Wrong Answer
29 / 99 testcases passed
Input
heights =
[2,1,2]
Use Testcase
Output
2
Expected
3*/

// Used a formula (nse - pse - 1) * height
// Brute force
// The formula used is heights[i]*(NSE[i]-PSE[i]-1)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        int n = heights.size();
        vector<int> pse(n, -1);
        vector<int> nse(n, -1);
        stack<int> st;

        // Previous smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                pse[i] = -1;
            } else {
                pse[i] = st.top();
            }
            st.push(i);
        }

        // Popping all the elements to make the stack empty
        while (!st.empty()) {
            st.pop();
        }

        //For Next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }

        // Largest Area of Rectangle
        for (int i = 0; i < n; i++) {
            int length = nse[i] - pse[i] - 1;
            int area = heights[i] * length;
            maxi = max(maxi, area);
        }
        return maxi;
    }
};
