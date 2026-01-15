/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void preOrder(Node *root, int val, map<int, vector<int>> &mp){
        if(root == NULL)    return;
        mp[val].push_back(root->data);
        preOrder(root->left, val+1, mp);
        preOrder(root->right, val, mp);
    }
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        map<int, vector<int>> mp;
        
        preOrder(root, 0, mp);
        for(auto d:mp){
            for(auto it:d.second){
                ans.push_back(it);
            }
        }
        return ans;
    }
};