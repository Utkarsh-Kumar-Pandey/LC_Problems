//  https://www.youtube.com/watch?v=UmJT3j26t1I
// The condition if (preorder[i] > upperbound) is stopping further construction in the left subtree.
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return solve(preorder, i, INT_MAX);
    }
    TreeNode* solve(vector<int>& preorder, int& i, int upperbound) {
        if (i == preorder.size() || preorder[i] > upperbound) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        // While Creating the left subtree each time the upper bound is recreated for each node.
        root->left = solve(preorder, i, root->val);
        // For right subtree the upperbound remains the same as previous.
        root->right = solve(preorder, i, upperbound);
        return root;
    }
};