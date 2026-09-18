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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy =new ListNode(0);

        while(head!= NULL){
            ListNode* nextNode=head->next;
            ListNode* prev=dummy;
            while(prev->next!= NULL && prev->next->val < head->val){
               prev= prev->next;
                
            }
            head->next= prev->next;
            prev->next=head;
             head = nextNode;
        }
        return dummy->next;
    }
};