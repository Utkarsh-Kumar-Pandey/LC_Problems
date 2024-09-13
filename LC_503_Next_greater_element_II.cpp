//Watched the official solution 
//https://www.youtube.com/watch?v=7PrncD7v9YQ
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> newnums(2 * n);
        vector<int> v(n,-1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            newnums[i] = nums[i];
            newnums[i + n] = nums[i];
        }
        int pos = 2 * n - 1;
        for (int i = pos; i >= 0; i--) {
            while (!st.empty() && newnums[i] > st.top()) {
                st.pop();
            }
            if (i < n) {
                while (!st.empty() && newnums[i] >= st.top()) {
                    st.pop();
                }
                // if stack not empty
                if (!st.empty()) {
                    v[i] = st.top();
                }
            }
            st.push(newnums[i]);
        }
        return v;
    }
};

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int maxi=-2;
        int pos=-10;
        if (n == 1) {
            ans.push_back(-1);
            return ans;
        }
        for(int k=0;k<nums.size();k++){
            if(nums[k]>maxi){
                maxi=nums[k];
                pos=k;
            }

        }
        for(int i=0;i<n;i++){

            for(int j=1;j<n;j++){
                int next=(i+j)%n;
                if(i==pos){
                    ans.push_back(-1);
                    break;
                }
                if(nums[next]>nums[i]){
                    ans.push_back(nums[next]);
                    break;
                }
            }
        }
        return ans;
        
    }
};
/*
My approach [Wrong] 68/223 passed
second loop starts checking from 0th index that means the greater element can be on the left side of the element
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>ans;
        int maxi=-2;
        int pos=-10;
        for(int k=0;k<nums.size();k++){
            if(nums[k]>maxi){
                maxi=nums[k];
                pos=k;
            }

        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(i==pos){
                    ans.push_back(-1);
                    break;
                }
                else if(nums[i]<nums[j]){
                    ans.push_back(nums[j]);
                    break;
                }


            }
        }
        return ans;
        
    }
};*/