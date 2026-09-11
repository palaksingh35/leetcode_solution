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
    void insertAtEnd( ListNode* &ansHead, ListNode* &end,int val){
        ListNode* temp= new ListNode(val);
         if(ansHead==NULL){
            ansHead=temp;
            end=temp;
         }else{
            end->next=temp;
            end=temp;
         }
    }
   
    int carry= 0;
    
    ListNode* add(ListNode* l1, ListNode* l2){
        ListNode* ansHead = NULL;
         ListNode* end = NULL;
        
        
        while(l1 != NULL || l2 !=NULL || carry!=0){
             int val1 = 0;
            if(l1 != NULL)
                val1 = l1->val;
                
            int val2 = 0;
            if(l2!=NULL)
                val2 = l2->val;
            int sum= carry+ val1+ val2;
            int digit= sum %10;
            insertAtEnd(ansHead,end,digit);
            carry= sum / 10;
            if (l1 != NULL)
                l1 = l1->next;

            if (l2 != NULL)
                l2 = l2->next;
        
        }
        return ansHead;
        }
      
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
         return add(l1,l2);
        
        
    }
   
};