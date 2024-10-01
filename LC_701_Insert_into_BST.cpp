class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        TreeNode* ans = root;
        while (root) {
            if (val > root->val) { // Will check Right side
                if (root->right != NULL) {
                    root = root->right;
                } else {
                    root->right = new TreeNode(
                        val); // If it's leaf node we insert it as a new node
                    break;
                }
            } 
            else {
                if (root->left != NULL) {
                    root = root->left;
                } else {
                    root->left = new TreeNode(val);
                    break;
                }
            }
        }
        // Returning the previously stored pointer as root is being changed here.
        return ans;
    }
};