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
    int isValid(TreeNode* root , long minval, long maxval){
       
        if(root==NULL){
            return 1;
        }
         int val=root->val;
         if (val <= minval || val >= maxval) {
          return false;
            }
        return isValid(root->left, minval, val) && isValid(root->right, val, maxval); 
        }
        
    
    
public:
    bool isValidBST(TreeNode* root) {
        long minval=LONG_MIN;
        long maxval=LONG_MAX;
       return  isValid(root, minval, maxval);

    }
};