class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cities(n, vector<int>(n, INT_MAX));
        map<int, int> m;
        for (auto i : edges) {
            cities[i[0]][i[1]] = i[2];
            cities[i[1]][i[0]] = i[2];
        }
        for (int i = 0; i != n; i++) {
            cities[i][i] = 0;
        }
        for (int via = 0; via != n; via++) {
            for (int i = 0; i != n; i++) {
                for (int j = 0; j != n; j++) {
                    if (cities[i][via] != INT_MAX && cities[via][j] != INT_MAX)
                        cities[i][j] = min(cities[i][j],
                                           (cities[i][via] + cities[via][j]));
                }
            }
        }
        for (int i = 0; i != n; i++) {
            for (int j = 0; j != n; j++) {
                if (cities[i][j] <= distanceThreshold)
                    m[i]++;
            }
        }

        int mn = INT_MAX, ans = 0;

        for (auto itr : m) {
            if (itr.second <= mn) {
                ans = itr.first;
                mn = itr.second;
            }
        }
        return ans;
    }
};