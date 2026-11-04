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
    
   void solve(TreeNode* root, int targetSum, int sum,vector<int>& currSum, vector<vector<int>>& ans){
           if(root==NULL)
           return ;
            currSum.push_back(root->val);
            sum=sum+root->val;
        if(root->left==NULL && root->right==NULL){
           
            if(sum==targetSum){
                ans.push_back(currSum);
            }
        }
        
         solve(root->left, targetSum, sum, currSum, ans);

         solve(root->right, targetSum, sum, currSum, ans);
      
       
        currSum.pop_back();
}
        
        
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int>currSum;
        int sum=0;
        solve(root, targetSum, sum, currSum, ans);

        return ans;
          
        
    }
};