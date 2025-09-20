class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        // int n = INT_MIN;
        // map<int, int> inDeg;

        // for(int i = 0; i!=edges.size(); i++){
        //     inDeg[edges[i][0]]++;
        //     inDeg[edges[i][1]]++;
        //     n = max(n, max(edges[i][1], edges[i][0]));
        // }

        // for(auto itr = inDeg.begin(); itr!=inDeg.end(); itr++ ){
        //     if(itr->second==n-1) return itr->first;
        // }

        int n1 = edges[0][1], n2 = edges[0][0];
        if(n1==edges[1][1] || n1==edges[1][0]) return n1;
        else return n2;

        return -1;
    }
};