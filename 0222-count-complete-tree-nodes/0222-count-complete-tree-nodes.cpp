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
        int leftHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            node = node->left;
            height++;
        }
        return height;
    }

    int rightHeight(TreeNode* node) {
        int height = 0;
        while (node) {
            node = node->right;
            height++;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        int cnt=0;
        if (root == NULL) {
            return 0;
        }
        int left=leftHeight(root);
        int right=rightHeight(root);
        if(left==right){
         return (1<<left)-1;
        }
         return 1 + countNodes(root->left)
                 + countNodes(root->right);
    }
};