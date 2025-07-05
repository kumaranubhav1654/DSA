class Solution {
public:
    int findUp(int t, vector<int>& parent) {
        if (parent[t] == t)
            return t;
        return parent[t] = findUp(parent[t], parent);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp;
        int n = accounts.size();
        vector<int> parent(n);
        
        for (int i = 0; i != n; i++)
            parent[i] = i;

        for (int i = 0; i != n; i++) {
            for (int j = 1; j != accounts[i].size(); j++) {
                string mail = accounts[i][j];
                if (mp.find(mail) == mp.end()) {
                    mp[mail] = i;
                } else {
                    int u = findUp(i, parent);
                    int v = findUp(mp[mail], parent);
                    if (u != v)
                        parent[u] = v;
                }
            }
        }

        vector<vector<string>> mail(n);

        for (auto i : mp) {
            int up = findUp(i.second, parent);
            mail[up].push_back(i.first);
        }

        vector<vector<string>> ans;

        for (int i = 0; i != n; i++) {
            if (!mail[i].empty()) {
                sort(mail[i].begin(), mail[i].end());
                vector<string>tmp;
                tmp.push_back(accounts[i][0]);
                tmp.insert(tmp.end(), mail[i].begin(), mail[i].end());
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};