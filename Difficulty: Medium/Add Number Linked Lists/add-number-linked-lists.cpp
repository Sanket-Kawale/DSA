/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
  Node* reverseLL(Node* head){
      Node* curr = head;
      Node* prev = NULL;
      Node* next = NULL;
      while(curr != NULL){
          next = curr->next;
          curr->next = prev;
          prev = curr;
          curr = next;
      }
      return prev;
  }
  Node* addLL(Node* head1, Node* head2){
      int carry = 0;
      
      Node* ansHead = NULL;
      Node* ansTail = NULL;
      
      while(head1 != NULL && head2 != NULL){
          int sum = carry + head1->data + head2->data;
          
          int digit = sum%10;
          insertAtTail(ansHead, ansTail, digit);
          carry = sum/10;
          head1 = head1->next;
          head2 = head2->next;
      }
      while(head1 != NULL){
          int sum = carry + head1->data;
          
          int digit = sum%10;
          insertAtTail(ansHead, ansTail, digit);
          carry = sum/10;
          head1 = head1->next;
      }
      while(head2 != NULL){
          int sum = carry + head2->data;
          
          int digit = sum%10;
          insertAtTail(ansHead, ansTail, digit);
          carry = sum/10;
          head2 = head2->next;
      }
      while(carry != 0){
          int sum = carry;
          
          int digit = sum%10;
          insertAtTail(ansHead, ansTail, digit);
          carry = sum/10;
      }
      return ansHead;
  }
  void insertAtTail(Node* &head, Node* &tail, int value){
      Node* temp = new Node(value);
      
      if(head == NULL){
          head = temp;
          tail = temp;
          return;
      }
      else{
          tail->next = temp;
          tail = temp;
      }
  }
  Node* trimLeadingZeros(Node* head){
      if(!head) return head;
      while(head && head->data == 0 && head->next){
          head = head->next; // drop zero nodes at front
      }
      return head;
  }
  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        head1 = reverseLL(head1);
        head2 = reverseLL(head2);
        
        Node* ans = addLL(head1,head2);
        ans = reverseLL(ans);
        ans = trimLeadingZeros(ans);
        
        return ans;
    }
};