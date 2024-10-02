class Solution {
public:
    void helper(TreeNode*root,vector<int>&ans,bool flag){
        if(root==NULL){
            return;
        }
        helper(root->left,ans,flag);
        ans.push_back(root->val);
        helper(root->right,ans,flag);
    }
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        bool flag=true;
        helper(root,ans,flag);
        for(int i=1;i<ans.size();i++){
            if(ans[i-1]>=ans[i]){
                flag=false;
                break;
            }
        }
        return flag;
        
    }
};