class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        int first=*max_element(nums1.begin(),nums1.end());
        int second=*max_element(nums2.begin(),nums2.end());
        return second-first;
    }
};
