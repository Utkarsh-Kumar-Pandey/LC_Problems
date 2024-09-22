// 1 2 3 4 5 N 7 N N 6 N N N
class Solution {
public:
    // Reverse pre order traversal Root R L
    void helper(TreeNode* root, vector<int>& ans, int level) {
        if (root == NULL) {
            return;
        }
        if (level == ans.size()) {
            ans.push_back(root->val);
        }
        helper(root->right, ans, level + 1);
        helper(root->left, ans, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        helper(root, ans, 0);
        return ans;
    }
};