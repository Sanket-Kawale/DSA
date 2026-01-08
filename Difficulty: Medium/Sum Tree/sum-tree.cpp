/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
    pair<bool, int> sum(Node* root){
        if(root == NULL){
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        
        if(root->left == NULL && root->right == NULL){
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        
        pair<bool, int> left = sum(root->left);
        pair<bool, int> right = sum(root->right);
        
        bool leftAns = left.first;
        bool rightAns = right.first;
        
        bool condn = root->data == left.second+right.second;
        
        pair<bool,int> ans;
        if(leftAns && rightAns && condn){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
        }
        return ans;
    }
    bool isSumTree(Node* root) {
        return sum(root).first;
        
    }
};