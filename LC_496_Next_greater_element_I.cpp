class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;
        // traversing from back
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // if stack already empty
            if (st.empty()) {
                mp[nums2[i]] = -1;
            }
            // Stack is not empty and the number is greater than the top of the
            // stack
            else if (!st.empty() && nums2[i] > st.top()) {
                while (!st.empty() && nums2[i] > st.top()) {
                    st.pop();
                }
                // While popping if the stack becomes empty
                if (st.empty()) {
                    mp[nums2[i]] = -1;
                } else {
                    mp[nums2[i]] = st.top();
                }
            }
            // if the number is smaller than the top of stack
            else if (nums2[i] < st.top()) {
                mp[nums2[i]] = st.top();
            }
            // push the element in monotonic stack
            // This won't come under else block because in every condition the element needs to be pushed in the stack 
            st.push(nums2[i]);
            
        }
        // Finding the mapped element of map
        for (int i = 0; i < nums1.size(); i++) {
            nums1[i] = mp[nums1[i]];
        }
        return nums1;
    }
};