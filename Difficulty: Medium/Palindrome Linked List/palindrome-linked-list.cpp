/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/
//APPROACH 1
#include<vector>
class Solution {
  private:
  bool checkPalindrome(vector <int> arr){
      int n = arr.size();
      int s = 0;
      int e = n-1;
      while(s<=e){
          if(arr[s] != arr[e]){
              return false;
          }
              s++;
              e--;
      }
      return true;
  }
  public:
    bool isPalindrome(Node *head) {
        vector<int> arr;
        Node* temp = head;
        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
            // return checkpalindrome(arr);
        }
        return checkPalindrome(arr);
    }
};