class Solution {
public:
    bool check(TreeNode* p, TreeNode* q, bool& flag) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        bool left = check(p->left, q->left, flag);
        bool right = check(p->right, q->right, flag);

        return left && right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        bool ans = check(p, q, flag);

        return ans;
    }
};