class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)return false;
        long long tmp = 0, xCopy = x;
        while(x){
            tmp = tmp*10+ x%10;
            x=x/10;
        }
        if(tmp == xCopy) return true;
        else return false;
    }
};