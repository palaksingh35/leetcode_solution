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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
        return NULL;
        // // Checking if at least k nodes are available
        ListNode* temp = head;
        int count = 0;

        while(temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        if(count < k) {
            return head;
        }
        // reverse first k nodes
        ListNode* curr= head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        int cnt=0;
        
        while(curr!=NULL && cnt < k){
            next = curr->next;
           curr->next=prev;
           prev= curr;
           curr=next;
           cnt++;
        }
        // remaining case solve by recursive call
        if(next!=NULL){
            head->next=reverseKGroup(next,k);
        }
        // return the head of the list
        return prev;
    }
};