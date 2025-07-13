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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        int ans = INT_MIN;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while(!q.empty()){
            int s = q.size();
            unsigned long long minIndex = q.front().second;
            unsigned long long first, last;

            while(s--){
                auto [rt, i] = q.front();
                q.pop();
                i -= minIndex;
                if (s == 0) last = i;

                if(rt->left) q.push({rt->left, 2*i+1});
                if(rt->right) q.push({rt->right, 2*i+2});
            }
            ans = max(ans , (int)(last)+1);
        }
        return ans;
    }
};