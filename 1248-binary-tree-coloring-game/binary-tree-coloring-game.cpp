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
    TreeNode* dfs(TreeNode* root, int x){
        if(root == NULL || root->val == x) return root;
        TreeNode* left = dfs(root->left, x);
        if(left!=NULL) return left;
        TreeNode* right = dfs(root->right, x);
        return right;
    }
    int size(TreeNode* root){
        if(root==NULL) return 0;
        return size(root->left) + size(root->right) + 1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode* tmp = root;
        TreeNode* p1 = dfs(root, x);

        int lh = 0, rh = 0;

        if(p1->left)
         lh = size(p1->left);
        
        if(p1->right)
         rh = size(p1->right);

        int ct = max(n - (lh+rh+1), max(lh, rh));

        if(ct <= n/2) return false;
        else return true;
    }
};