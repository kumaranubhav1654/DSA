/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue <tuple<int, int, TreeNode*>> q;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;

        q.push({0, 0, root});

        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto [col, row, node] = q.front();
                pq.push({col, row, node->val});
                cout<<col<<" "<<row<<" "<<node->val<<endl;
                q.pop();
                if (node->left)
                    q.push({col - 1, row + 1, node->left});
                if (node->right)
                    q.push({col + 1, row + 1, node->right});
            }
        }

        map<int, vector<int>>mp;

        while (!pq.empty()) {
            auto [col, row, node] = pq.top();
            pq.pop();
            mp[col].push_back(node);
        }

        for(auto i : mp){
            ans.push_back(i.second);
        }

        return ans;
    }
};