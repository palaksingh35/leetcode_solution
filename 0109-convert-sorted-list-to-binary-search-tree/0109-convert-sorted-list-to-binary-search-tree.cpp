/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
     TreeNode* solve(int s, int e ,vector<int>& in){
        if(s>e)
        return NULL;
        int mid=(s+e)/2;
         TreeNode* root=new TreeNode(in[mid]);
        root->left= solve(s,mid-1, in);
        root->right= solve(mid+1, e, in);
        return root;
     }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>in;
        while(head != NULL) {
         in.push_back(head->val);
         head = head->next;
}
       return solve(0,in.size()-1,in);

        
    }
};