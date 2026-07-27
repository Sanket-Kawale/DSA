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
        if(head == NULL)        return NULL;
        
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);

            copy->next = curr->next;
            curr->next =  copy;

            curr = copy->next;
        }

        curr = head;
        while(curr){
            if(curr->random != NULL){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;

        while(curr){
            Node* copy = curr->next;

            curr->next = copy->next;
            
            copyTail->next = copy;
            copyTail = copy;

            curr = curr->next;
        }
        return dummy->next;
    }
};