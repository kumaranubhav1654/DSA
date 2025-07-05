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
    void helper(vector<string> &ans, TreeNode* root, string s){
        if(root->left==NULL && root->right==NULL) ans.push_back(s);
        if(root->left)
            helper(ans, root->left, s+"->"+to_string(root->left->val));
        
        if(root->right)
            helper(ans, root->right, s+"->"+to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string s = to_string(root->val);
        helper(ans, root, s);
        return ans;
    }
};