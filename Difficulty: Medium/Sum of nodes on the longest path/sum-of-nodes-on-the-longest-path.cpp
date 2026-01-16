/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void solve(Node* root, int sum, int &maxSum, int len, int &maxLen){
        if(root == NULL){
            if(len > maxLen){
                maxLen = len;
                maxSum = sum;
            }
            if(len == maxLen){
                maxSum = max(sum, maxSum);
            }
            return;
        }
        len = len+1;
        sum = sum + root->data;
        solve(root->left, sum, maxSum, len, maxLen);
        solve(root->right, sum, maxSum, len, maxLen);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        int sum = 0;
        int maxSum = 0;
        int len = 0;
        int maxLen = 0;
        solve(root, sum, maxSum, len, maxLen);
        
        return maxSum;
    }
};