class Solution {
public:
    bool checkDivisibility(int n) {
        int tmp = n;
        int sm = 0, mul =1;
        while(tmp){
            int t = tmp%10;
            sm+=t; mul=mul*t;
            tmp = tmp/10;
        }

        if(n%(sm+mul)==0) return true;
        return false;
    }
};