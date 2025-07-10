class Solution {
public:
    bool isValid(int i, int j, int n, int m){
        return ((i>=0 && j>=0)&& (i<n && j<m));
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
          greater<tuple<int, int, int>>>pq;

        vector<vector<int>>effort(n, vector<int>(m, INT_MAX));
         
        pq.push({0,0,0});

         while(!pq.empty()){
            auto [elevation, i , j] = pq.top();
            pq.pop();

            if(i==n-1 && j==m-1) return elevation;

            int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};

            for(int a = 0; a!=4; a++){
                int newI = i+dx[a], newJ= j+dy[a];
                if(isValid(newI, newJ, n, m)){
                    int ele = max(elevation, abs(heights[newI][newJ]- heights[i][j]));
                    if(effort[newI][newJ]>ele){
                        pq.push({ele, newI, newJ});
                        effort[newI][newJ] = ele;
                    }
                }
            }
         }

        return -1;
    }
};