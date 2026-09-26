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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       vector<int>arr;
        for(int i=0; i< lists.size(); i++){
            ListNode* curr=lists[i];
            while(curr!=NULL){
            arr.push_back(curr->val);
            curr=curr->next;
        }
    }
        sort(arr.begin(),arr.end());
        ListNode* head=NULL;
        ListNode* tail=NULL;
        for(int i=0; i< arr.size();i++){
           ListNode* newNode=new ListNode(arr[i]);
           if(head==NULL){
            head= newNode;
            tail=newNode;
           }else{
            tail->next=newNode;
            tail=newNode;
           }
            }
        
        
      return head;
         
    }
};