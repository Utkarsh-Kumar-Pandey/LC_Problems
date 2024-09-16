//My Approach
//40/51 Test cases passed
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n-k+1;i++){
            int j=i+k;
            int maxi=nums[i];
            for(int l=i;l<j;l++){
                maxi=max(maxi,nums[l]);
            }
            ans.push_back(maxi);
        }
        return ans;
    }
};

// To Optimise this code we need to push the element and pop element from the given array
// We will use double ended queue for solving this as it can perform operations of push and pop on front and back with better complexity 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // Remove when window exceeds k (Neccessary for popping out the
            // front element)
            while (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // Max element at the top of the stack
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};