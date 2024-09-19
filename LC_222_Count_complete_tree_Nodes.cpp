class Solution {
public:
    void helper(TreeNode*root,int &count){
        if(root==NULL){
            return;
        }
        count++;
        helper(root->left,count);
        helper(root->right,count);
    }
    int countNodes(TreeNode* root) {
        int count=0;
        helper(root,count);
        return count;
        
    }
};