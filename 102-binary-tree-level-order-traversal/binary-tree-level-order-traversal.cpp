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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans ;
        queue<TreeNode*>q;
        
        if(!root) return ans;

        q.push(root);

        while(!q.empty()){
            int s= q.size();
            vector<int>tmp;
            while(s--){
                auto a = q.front();
                tmp.push_back(a->val);
                q.pop();
                if(a->left) q.push(a->left);
                if(a->right) q.push(a->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};