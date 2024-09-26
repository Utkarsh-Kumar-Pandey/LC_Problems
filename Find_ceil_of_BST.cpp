int findCeil(Node* root, int input) {
    int ceil=-1;
    while(root!=NULL){
        if(root->data==input){
            ceil=root->data;
            return ceil;
        }
        if(input>root->data){
            root=root->right;
        }
        else{
            ceil=root->data;
            root=root->left;
        }
    }
    return ceil;
}