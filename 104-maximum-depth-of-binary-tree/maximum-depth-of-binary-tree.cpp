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
    int Depth(TreeNode* root, int d){
        if(root == NULL)    return 0;

        int leftDepth = Depth(root->left, d);
        int rightDepth = Depth(root->right, d);

        return 1 + max(leftDepth, rightDepth); 
    }
    int maxDepth(TreeNode* root) {
        int d = 0;
        return Depth(root, d);
    }
};