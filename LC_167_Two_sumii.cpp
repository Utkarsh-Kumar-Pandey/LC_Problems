//My solution using 2 pointers
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int i = 0;
        int j = 1;
        int n = numbers.size();
        while (i < n - 1) {
            if (j == n) {
                i += 1;
                j = i + 1;
            }
            int sum = 0;
            sum = numbers[i] + numbers[j];
            if (sum == target) {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
            j += 1;
        }
        return ans;
    }
};
//Other way to solve this
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> mapp;
        int presum = 0;

        for (int i = 0; i < numbers.size(); i++) {
            presum = target - numbers[i];
            if (mapp.find(presum) == mapp.end()) {
                mapp[numbers[i]] = i;
            } else {
                return {mapp[presum] + 1, i + 1};
            }
        }
        return {-1, -1};
    }
};