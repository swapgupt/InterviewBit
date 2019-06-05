/** Convert the given tree to the mirror of itself **/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 

void Solution::convertToMirror(TreeNode* A){
    if (A!=NULL){
        if (A->left) convertToMirror(A->left);
        if (A->right) convertToMirror(A->right);
        
        TreeNode* temp = A->right;
        A->right = A->left;
        A->left = temp;
    }
}