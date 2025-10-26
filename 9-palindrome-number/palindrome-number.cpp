class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x!=0 && x%10==0))return false;
        long long tmp = 0;
        while(x > tmp){
            tmp = tmp*10 + x%10;
            x=x/10;
        }
        if(tmp == x || x == tmp/10) return true;
        else return false;
    }
};