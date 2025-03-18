/*// My first approach failed at
/*
nums = [3,5,3,4]
k = 2
Stdout
4 5 3 
Output
9
Expected
8
Why/Reason?
It is removing all the duplicates in the whole array which results in removing the elements in the array that might not contribute to the subarray and removing it is of no use
In the failed test case 
it is resulting to the array 3,5,4 which is substantially removing out the element 3 from the end which can contribute to the window of length 3 in future as 5,3,4 *//*
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<long long> st(nums.begin(), nums.end());
        for (int num : st) {
            cout << num << " ";
        }
        cout << endl;
        long long mod = 1e9 + 7;
        vector<long long> nums2(st.begin(), st.end());
        long long sum = 0;
        long long maxi = INT_MIN;
        // Edge case if the size is less than the given k value
        if(nums2.size()<k){
            return 0;
        }
        for (long long i = 0; i < k; i++) {
            sum += nums2[i];
        }
        maxi = max(maxi, sum);
        int left = 0;
        for (long long j = k; j < nums2.size(); j++) {
            sum -= nums2[left];
            left++;
            sum += nums2[j];
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};*/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<long long> st;
        int left=0;
        long long maxi=INT_MIN;
        long long sum=0;

        for(int i=0;i<nums.size();i++){
            // if found in the set already then move forward
            while(st.count(nums[i])){
                st.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
            st.insert(nums[i]);
            sum += nums[i];
            // if size equal to k then stop
            if(i-left+1==k){
                maxi=max(maxi,sum);
                st.erase(nums[left]);
                sum-=nums[left];
                left++;
            }

        }
        if(maxi==INT_MIN){
            return 0;
        }
        return maxi;
        
    }
};

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long sum=0;
        int n=nums.size();
        int st=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mpp[nums[i]]++;
            // Removing the sum of prev 
            while(mpp[nums[i]]>1){
                mpp[nums[st]]--;
                sum-=nums[st];
                st++;
            }
            if(i-st==k-1){
                ans=max(ans,sum);
                sum-=nums[st];
                mpp[nums[st]]--;
                st++;
            }
        }
        return ans;
        
    }
};
