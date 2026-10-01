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

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL && n==1 ){
            return NULL;
        }
       ListNode* curr = head;
       int cnt=0;
       while (curr!= NULL) {
        cnt++;
        curr=curr->next;
        
       }
       if(cnt==n){
        return head->next;
       }
      curr= head;
      for(int i=0; i< cnt-n-1; i++){
        curr= curr->next;
      }
      curr->next=curr->next->next;
      return head;
        
    }
};