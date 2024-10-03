class Solution {
public:
    void solve(vector<int>& ans, TreeNode* root, int k) {
        if (root == NULL) {
            return;
        }
        solve(ans,root->left,k);
        ans.push_back(root->val);
        solve(ans,root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        solve(ans, root, k);
        unordered_map<int, int> mpp;
        for (int i = 0; i < ans.size(); i++) {
            int prefix_sum = k - ans[i];
            if (mpp.find(prefix_sum) != mpp.end()) {
                return true;
                break;
            }
            mpp[ans[i]] = i;
        }
        return false;
    }
};