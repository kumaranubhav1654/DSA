class Solution {
public:
    int count(int n, vector<int> &v){
        if(n<0) return 0;
        if(n==0) return 1;
        if(v[n]!=-1) return v[n];
        
        return v[n] = count(n-1, v) + count(n-2,  v);
    }
    int climbStairs(int n) {
        if(n==0) return 0;
        vector<int> v(n+1, -1);
        return count(n, v);
    }
};