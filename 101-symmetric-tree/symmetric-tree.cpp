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
    bool helper(TreeNode* rl, TreeNode* rr){
        if(rl == NULL && rr == NULL) return true;
        if(rl == NULL || rr == NULL) return false;
        if(rl->val != rr->val) return false;
        return helper(rl->left, rr->right) && helper(rl->right, rr->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return false;
        return helper(root->left, root->right);
    }
};