/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    void insertAtTail(Node* &head, Node* &tail, int val){
       Node* newNode= new Node(val);
       if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
       }else{
        tail->next=newNode;
        tail=newNode;
       }
    }
public:
    Node* copyRandomList(Node* head) {
        // step 1 - making a clone linked list first without random ptr
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        Node* temp= head;
        while(temp!= NULL){
            insertAtTail(clonehead,clonetail,temp->val);
            temp=temp->next;
        }
        // step-2: save the mapping lsit of original list 
        unordered_map<Node* , Node*> oldToNewNode;// making map of the original node
        Node* originalNode=head;
        Node* cloneNode= clonehead;
        while(originalNode!= NULL && cloneNode!=NULL ){
            oldToNewNode[originalNode]=cloneNode;
            originalNode= originalNode->next;
            cloneNode=cloneNode->next;
        }
        // setting random of original to cloneNode
        originalNode=head;
        cloneNode= clonehead;
        while(originalNode!= NULL){
            cloneNode ->random=oldToNewNode[originalNode-> random];
             originalNode= originalNode->next;
            cloneNode=cloneNode->next;
        }
       return clonehead; 
    }
};