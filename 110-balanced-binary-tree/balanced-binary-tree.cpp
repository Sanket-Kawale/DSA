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
    pair<bool, int> balanceFast(TreeNode* root){
            if(root == NULL){
                pair<bool, int> p = make_pair(true, 0);
                return p; 
            }

        pair<bool, int> left = balanceFast(root->left);
        pair<bool, int> right = balanceFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = 1+max(left.second, right.second);
        ans.first = (leftAns && rightAns && diff);

        return ans;
    }

    bool isBalanced(TreeNode* root) {
        pair<bool, int> ans;
        ans = balanceFast(root);

        return ans.first;
    }
};