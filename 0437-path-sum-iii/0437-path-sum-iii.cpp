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
    void solve(TreeNode* root, int targetSum, int &count,vector<int>path ){
           if(root==NULL)
           return ;
            path.push_back(root->val);
              solve(root->left, targetSum, count, path);

             solve(root->right, targetSum, count, path);
             int size=path.size();
              long sum=0;
             for(int i=size-1; i>=0; i--){
                
                sum+=path[i];
                if(sum==targetSum){
                    count++;
                }
             }
             path.pop_back();
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count=0; 
        vector<int>path; 
        solve(root, targetSum, count, path);
       return count;

    }
};