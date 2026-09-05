/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
     ListNode* floydCycle(ListNode* head){
        ListNode* slow= head; 
        ListNode* fast= head;
        while(fast!=NULL && fast->next !=NULL){
            slow=slow->next ;
            fast= fast->next->next;
            if(slow== fast){
                return slow;
            }
        }
            return NULL;
        
     }
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL){
            return NULL;

        }
        ListNode* intersection=floydCycle(head);
        ListNode* slow=head;
        while(slow!= intersection){
            slow=slow->next;
            if(intersection == NULL) {
            return NULL;
               }
            intersection= intersection->next;
        }  
        return slow; 
        
    }
};