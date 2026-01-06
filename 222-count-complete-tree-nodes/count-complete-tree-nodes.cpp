/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int inorder(TreeNode* root, int &cnt){
        if(root == NULL)    return 0;
        if(root->left){
        inorder(root->left, cnt);
        cnt++;
        }
        if(root->right){
        inorder(root->right, cnt);
        cnt++;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        int cnt = 1;
        return inorder(root, cnt);
    }
};