class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string, int> mpp;
        for (int i = 0; i < arr.size(); i++) {
                mpp[arr[i]]++;
        }
        for (int i = 0; i < arr.size(); i++) { 
            if (mpp[arr[i]] == 1) { // Only occurred 1ce
                k--;
                if (k == 0) {
                    return arr[i]; 
                }
            }
        }
        return "";
    }
};

