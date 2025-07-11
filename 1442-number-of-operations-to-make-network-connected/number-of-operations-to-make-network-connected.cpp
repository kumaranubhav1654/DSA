class Solution {
public:
vector<int>parent;
vector<int>size;
    void unionBySize(int u, int v, int &extraEdges){
        int up = findUParent(u);
        int vp = findUParent(v);

        if(up==vp) {
            extraEdges++;
            return;
        }
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
        return parent[node] = findUParent(parent[node]);
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extraEdges = 0, totalComponents = 0;
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) parent[i] = i;
        for(int i = 0; i!=connections.size(); i++){
                unionBySize(connections[i][0], connections[i][1], extraEdges);
        }
        for(int i = 0; i!=n; i++){
            if(parent[i]==i) totalComponents++;
        }
        if(extraEdges>=totalComponents-1) return totalComponents-1;
        else return -1;
    }
};