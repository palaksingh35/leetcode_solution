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
     TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index, int inorderStart, int inorderEnd, int n){
        if(index>= n ||  inorderStart > inorderEnd ){
            return NULL;
        }
        int element=preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos = 0;

        for(int i = inorderStart; i <= inorderEnd; i++){
          if(inorder[i] == element){
          pos = i;
          break;
    }
}
         root->left=solve(preorder, inorder, index,inorderStart, pos-1, n );
           root->right=solve(preorder, inorder, index,pos+1,inorderEnd, n );
           return root;

    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex=0;
        int n = inorder.size();
       return solve(preorder, inorder, preorderIndex, 0,n-1, n );
        
    }
};