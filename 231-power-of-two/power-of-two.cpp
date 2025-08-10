class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        if(n%2==1 || n<=0) return false;
        
        while(n){
            if(n==2) break;
            n = n/2;
            if(n%2==1) return false;
        }

        return true;
    }
};