class Solution {
public:
    int maximum69Number (int num) {
        int ans = 0, count = 1, last = -1;
        while(num){
            int tmp = num%10;
            if(tmp == 6) last = count;
            ans += (tmp)*count;
            //cout<<ans<<endl;
            count=count*10;
            num=num/10;
        }
        if(last!=-1)
        return ans+3*(last);
        else return ans;
    }
};