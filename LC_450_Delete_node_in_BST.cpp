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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* curr = root;
        if (root->val == key) {
            return handle_subtree(root);
            // helper will attach rest nodes accordingly
        }
        while (root) {
            if (root->val < key) {
                if (root->right != NULL && root->right->val == key) {
                    root->right = handle_subtree(root->right);
                    break;
                } 
                else {
                    root = root->right;
                }
            } 
            else {
                if (root->left != NULL && root->left->val == key) {
                    root->left=handle_subtree(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
        }
        return curr;
    }
    TreeNode*handle_subtree(TreeNode*root){
        // If left subtree is NULL point it to right one.
        if(root->left==NULL){
            return root->right;
        }
        else if(root->right==NULL){
            return root->left;
        }
        // Finding the rightmost part of left subtree and then pointing it to right subtree
        TreeNode*right_subtree=root->right;
        TreeNode*left_subtree_rightmost=find_right_most(root->left);
        left_subtree_rightmost->right=right_subtree;
        return root->left;

    }
    TreeNode*find_right_most(TreeNode*root){
        if(root->right==NULL){
            return root;
        }
        return find_right_most(root->right);
    }
};