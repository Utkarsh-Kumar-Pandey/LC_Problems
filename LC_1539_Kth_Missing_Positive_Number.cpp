//My first approach 
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int, int> mpp;
        int maxi = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > maxi) {
                maxi = arr[i];
            }
            mpp[arr[i]]++;
        }
        vector<int> ans;
        for (int j = 1; j <= maxi + k; j++) {
            if (mpp.find(j) == mpp.end()) {
                ans.push_back(j);
            }
        }
        for (int l = 0; l < ans.size(); l++) {
            cout << ans[l];
            if (l == k - 1) {
                return ans[l];
                break;
            }
        }
        return ans[0];
    }
};
// Using Binary search
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // We appraoch using binary search by finding the number of elements missing out!
        // The element present - actual 1-based indexing
        // This gives the number of elements missed
        int low=0;
        int high=arr.size()-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if((arr[mid]-mid-1)<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low+k;
        
    }
};
