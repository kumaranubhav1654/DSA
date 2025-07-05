/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(unordered_map<TreeNode*, TreeNode*> &mp, TreeNode* root){
        if(root==NULL) return;
        if(root->left!=NULL){
            mp[root->left] = root;
            helper(mp, root->left);
        } 
        if(root->right!=NULL){
            mp[root->right] = root;
            helper(mp, root->right);
        } 
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> mp;
        helper(mp, root);
        map<TreeNode*, int> vis;

        queue<TreeNode*>q;
        q.push(target);
        vis[target] = 1;

        while(!q.empty() && k--){
            int s = q.size();
            while(s--){
                TreeNode* tmp = q.front();
                q.pop();
                if(tmp->left!=NULL && !vis[tmp->left]){
                    q.push(tmp->left);
                    vis[tmp->left] = 1;
                }
                if(tmp->right!=NULL && !vis[tmp->right]){
                    q.push(tmp->right);
                    vis[tmp->right] = 1;
                }
                if(mp[tmp]!=NULL && !vis[mp[tmp]]){
                q.push(mp[tmp]);
                vis[mp[tmp]] = 1;
                }
            }
        }
        while(!q.empty()){
            //if(q.front()!=target)
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};