class Solution {
public:
vector<int>parent;
vector<int>size;
vector<int>rank;
    void unionBySize(int u, int v){
        int up = findUParent(u);
        int vp = findUParent(v);

        if(up==vp) return;
        if(size[up]< size[vp]){
            parent[up] = vp;
            size[vp]+=size[up];
        }
        else{
            parent[vp] = up;
            size[up]+=size[vp];
        }
    }
    int findUParent(int node){
        if(parent[node]==node) return node;
        return parent[node] = findUParent( parent[node]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i!=n; i++) parent[i] = i;

        for(int i = 0; i!=n; i++){
            for(int j = 0; j!=n; j++){
                if(isConnected[i][j]==1) unionBySize(i, j);
            }
        }
        for(int i = 0; i!=n; i++){
            if(parent[i]==i) ans++;
        }

        return ans;
    }
};