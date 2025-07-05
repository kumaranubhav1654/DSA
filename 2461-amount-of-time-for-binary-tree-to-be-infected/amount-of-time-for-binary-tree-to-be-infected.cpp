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
    void helper(unordered_map<TreeNode*, TreeNode*> &mp, TreeNode* &target, TreeNode* root, int start){
        if(root==NULL)return;
        if(root->val==start) target = root;
        if(root->left){
            mp[root->left] = root;
            helper(mp, target, root->left, start);
        }
        if(root->right){
            mp[root->right] = root;
            helper(mp, target, root->right, start);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        int time = 0;
        unordered_map<TreeNode*, TreeNode*> mp;
        TreeNode* target;
        helper(mp, target, root, start);

        queue<TreeNode*>q;
        map<TreeNode*, int>vis;

        q.push(target);
        vis[target] = 1;

        while(!q.empty()){
            int s = q.size();
            while(s--){
                TreeNode* tmp = q.front();
                q.pop();

                if(tmp->left!=NULL && !vis[tmp->left]){
                    q.push(tmp->left);
                    vis[tmp->left]=1;
                    cout<<time<<" "<<tmp->left->val<<endl;
                }
                if(tmp->right!=NULL && !vis[tmp->right]){
                    q.push(tmp->right);
                    vis[tmp->right]=1;
                    cout<<time<<" "<<tmp->right->val<<endl;
                }
                if(mp[tmp]!=NULL && !vis[mp[tmp]]){
                    q.push(mp[tmp]);
                    vis[mp[tmp]]=1;
                    cout<<time<<" "<<mp[tmp]->val<<endl;
                }
            }
            time++;
        }
        return time-1;
    }
};