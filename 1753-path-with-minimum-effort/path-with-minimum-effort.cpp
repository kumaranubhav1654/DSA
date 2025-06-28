class Solution {
public:
    bool isValid(int i, int j, int m, int n) {
        return ((i >= 0 && j >= 0) && (i < m && j < n));
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        using Node = pair<int, pair<int, int>>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        pq.push({0,{0,0}});
        dist[0][0]=0;

        while(!pq.empty()){
            auto [h, add] = pq.top();
            pq.pop();

            int dx[] = {0, 0, 1, -1},
            dy[] = { 1, -1, 0, 0};

            int i = add.first, j = add.second;
            if (i == m - 1 && j == n - 1)
                ans = min(ans, h);
            for (int a = 0; a != 4; a++) {
                int ni = i + dx[a], nj = j + dy[a];
                if (isValid(ni, nj, m, n)){
                int effort = max(abs(heights[i][j] - heights[ni][nj]), h);
                    //cout<<ni<<" "<<nj<<" Dis"<<effort<<endl;
                    if(effort < dist[ni][nj]){
                    pq.push({effort, {ni, nj}});
                    dist[ni][nj] = effort;
                    }
                }
            }
        }
        return ans;
    }
};