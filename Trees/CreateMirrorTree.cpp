/** Create a new tree that is mirror of itself **/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

TreeNode* Solution::createMirror(TreeNode* A){
    if (A!=NULL){
        TreeNode* V = new TreeNode(A->val);
        V->right = createMirror(A->left);
        V->left = createMirror(A->right);
        
        return V;
    }
    return NULL;
}