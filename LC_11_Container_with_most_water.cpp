// My solution
// 2 Pointer approach 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int sum = 0;
        int maxsum = INT_MIN;

        while (i <= j) {

            if (height[i] < height[j]) {
                maxsum = max(maxsum, height[i] * (j - i));
                i++;
            } 
            
            else {
                maxsum = max(maxsum, height[j] * (j - i));
                j--;
            }
        }
        return maxsum;
    }
};