// https://youtu.be/1_5VuquLbXg Watched the Solution
// TC - O(3n)
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int n = height.size();
        vector<int> prefixmax(n);
        prefixmax[0] = height[0];
        for (int i = 1; i < n; i++) {
            prefixmax[i] = max(prefixmax[i - 1], height[i]);
        }

        vector<int> suffixmax(n);
        suffixmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixmax[i] = max(suffixmax[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            // The current height must be smaller than the left max and the
            // right max of the array
            int leftmax = prefixmax[i];
            int rightmax = suffixmax[i];
            if (height[i] < leftmax && height[i] < rightmax) {
                // The formula used is min(leftmax,rightmax)-height[i]
                sum += min(leftmax, rightmax) - height[i];
            }
        }
        return sum;
    }
};