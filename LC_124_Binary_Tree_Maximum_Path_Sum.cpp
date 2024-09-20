/*Formula Used root->value+maxi_left+maxi_right*/
class Solution {
public:
    int summ(TreeNode* root, int& max_sum) {
        if (root == NULL) {
            return 0;
        }
        // The Sum can be calculated for a node as
        // Left_sum+Right_sum+Node->value
        int left_summ = max(0, summ(root->left, max_sum));
        int right_summ = max(0, summ(root->right, max_sum));

        // Neglecting negative node->val,Doing this maximizes the result.

        max_sum = max(max_sum, left_summ + right_summ + root->val);

        return (root->val) + max(left_summ, right_summ);
    }
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        summ(root, max_sum);

        return max_sum;
    }
};