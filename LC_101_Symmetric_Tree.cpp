/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool check_symmetry(TreeNode* left_tree, TreeNode* right_tree) {
        // Checked if both are Null
        if (!left_tree && !right_tree) {
            return true;
        }
        // Checked if one of them isn't Null
        if (!left_tree || !right_tree) {
            return false;
        }
        return (left_tree->val == right_tree->val) &&
               check_symmetry(left_tree->left, right_tree->right) &&
               check_symmetry(left_tree->right, right_tree->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) {
            return true;
        }
        return check_symmetry(root->left, root->right);
    }
};