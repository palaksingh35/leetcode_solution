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
class Solution {
    ListNode* reverse(ListNode* head,ListNode* curr,ListNode*prev){
        if(curr==NULL){
      return  head=prev;
        
    }
     ListNode* forward=curr->next;
    
     curr->next = prev;
  return  reverse(head,forward,curr);
    
    
    }
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* curr=head;
       ListNode* prev=NULL;
     return  reverse(head,curr,prev);
    

        
    }
};
    
    