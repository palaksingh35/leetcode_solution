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

    struct Info {
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };
     int maxi = 0;

    Info solve(TreeNode* root) {

        
        if(root == NULL) {
            return {true, 0, INT_MAX, INT_MIN};
        }

        
        Info left = solve(root->left);
        Info right = solve(root->right);

        // Check BST condition
        if(left.isBST && right.isBST &&
           left.maxVal < root->val &&
           right.minVal > root->val) {

            int sum = root->val + left.sum + right.sum;

            maxi = max(maxi, sum);

            return { true,sum, min(root->val, left.minVal),max(root->val, right.maxVal)};
        }

        // invalid subtree bst
        return {false, 0, 0, 0};
    }

public:
    int maxSumBST(TreeNode* root) {
        maxi = 0;
        solve(root);
        return maxi;
    }
};