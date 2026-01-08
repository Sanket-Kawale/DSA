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
    int count(TreeNode* root, int &cnt){
        if(root == NULL)    return 0;
        if(root->left){
            count(root->left, cnt);
            cnt++;
        }
        if(root->right){
            count(root->right, cnt);
            cnt++;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        int cnt = 1;
        return count(root, cnt);
    }
};