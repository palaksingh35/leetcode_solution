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
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
          map<int, map<int, multiset<int>>> nodes;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root, {0, 0}});

        while(!q.empty()) {

            auto temp = q.front();
            q.pop();

            TreeNode* frontNode = temp.first;

            int row = temp.second.first;
            int col = temp.second.second;

            nodes[col][row].insert(frontNode->val);

            if(frontNode->left) {
                q.push({frontNode->left, {row+1, col-1}});
            }

            if(frontNode->right) {
                q.push({frontNode->right, {row+1, col+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto i : nodes) {

            vector<int> col;

            for(auto j : i.second) {

                for(auto k : j.second) {
                    col.push_back(k);
                }
            }

            ans.push_back(col);
        }

        return ans;
    }
};