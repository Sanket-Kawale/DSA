/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/
//APPROACH 1   
class Solution {
  private:
  void insertAtTail(Node* &head, Node* &tail, int data){
      Node* newNode = new Node(data);
      if(head == NULL){
          head = newNode;
          tail = newNode;
          return;
      }
      else{
              tail->next = newNode;
              tail = newNode;
      }
  }
  public:
    Node* cloneLinkedList(Node* head) {
        //1. create a clone of linear LL
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        //2.mapping original and clonenode
        unordered_map<Node*, Node*> oldToNew;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while(originalNode != NULL && cloneNode != NULL){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        //3. arranging order of random pointers
        originalNode = head;
        cloneNode = cloneHead;
        while(originalNode != NULL){
            cloneNode->random = oldToNew[originalNode->random];     //assigning values using clone
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};