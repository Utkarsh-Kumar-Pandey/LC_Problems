class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        long long sum = 0;
        vector<int> prevSmall(n, -1), nextSmall(n, n);
        stack<int> stack;
        for (int i = 0; i < n; ++i) {
            while (!stack.empty() && arr[stack.top()] > arr[i]) {
                stack.pop();
            }
            if (!stack.empty()) {
                prevSmall[i] = stack.top();
            }
            stack.push(i);
        }

        while (!stack.empty()) stack.pop();
        for (int i = n - 1; i >= 0; --i) {
            while (!stack.empty() && arr[stack.top()] >= arr[i]) {
                stack.pop();
            }
            if (!stack.empty()) {
                nextSmall[i] = stack.top();
            }
            stack.push(i);
        }
        
        for (int i = 0; i < n; ++i) {
            long long leftCount = i - prevSmall[i];
            long long rightCount = nextSmall[i] - i;
            sum += (arr[i] * leftCount * rightCount) % mod;
            sum %= mod;
        }
        
        return sum;
    }
};




