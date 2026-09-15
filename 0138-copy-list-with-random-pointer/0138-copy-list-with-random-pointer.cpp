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
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL) {
            return NULL;
        }

        // Step 1: Create clone nodes and insert them
        // between original nodes
        Node* temp = head;

        while (temp != NULL) {
            Node* clone = new Node(temp->val);

            clone->next = temp->next;
            temp->next = clone;

            temp = clone->next;
        }

        
        temp = head;

        while (temp != NULL) {

            if (temp->random != NULL) {
                temp->next->random = temp->random->next;
            }

            temp = temp->next->next;
        }

        //  Separate 
        Node* cloneHead = head->next;
        temp = head;

        while (temp != NULL) {

            Node* clone = temp->next;

            temp->next = clone->next;

            if (clone->next != NULL) {
                clone->next = clone->next->next;
            }

            temp = temp->next;
        }

        return cloneHead;
    }
};