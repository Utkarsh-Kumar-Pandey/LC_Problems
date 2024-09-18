/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode*root,vector<int>&ans){
        if(root!=NULL){
            ans.push_back(root->val);
            preorder(root->left,ans);
            preorder(root->right,ans);
        }
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==nullptr){
            return ans;
        }
        preorder(root,ans);

        return ans;
        
    }
};
- - - - - - - - - - - - - - -- - - - - - - - - - - -- - - - - - - - - - - -- - - - - - - - - - - -- - - - - - - - - - - -
class Solution {
public:
    void inorder(vector<int>&ans,TreeNode*root){
        if(root!=NULL){
            inorder(ans,root->left);
            ans.push_back(root->val);
            inorder(ans,root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        inorder(ans,root);
        return ans;
        
    }
};
- - - - - - - - - - - - - - -- - - - - - - - - - - -- - - - - - - - - - - -- - - - - - - - - - - -- - - - - - - - - - - -
class Solution {
public:
    void helper(TreeNode* root,vector<int>&ans){
        if(root!=NULL){
            helper(root->left,ans);
            helper(root->right,ans);
            ans.push_back(root->val);
        }
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        helper(root,ans);
        return ans;
        
    }
};