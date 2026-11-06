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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,
                int& index, int inorderStart, int inorderEnd){
         if(index < 0 || inorderStart > inorderEnd)
            return NULL;

          int element=postorder[index--];
           TreeNode* root = new TreeNode(element);
           int pos = 0;

        for(int i = inorderStart; i <= inorderEnd; i++){
          if(inorder[i] == element){
          pos = i;
          break;
    }
}
         root->right= solve(inorder, postorder,index, pos+1,inorderEnd);
         root->left= solve(inorder, postorder,index, inorderStart,pos-1 );
         return root;

    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
     int n = postorder.size();
      int index = n - 1;
     return solve(inorder, postorder,index,0,n-1 );
    }
};