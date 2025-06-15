class Solution {
public:
    int nextGreaterElement(int n) {
        map<int, int>mp;
        stack<int>st;
        int justGreater = 0, tmp = n, lastDigit = 0;
        while(tmp){
            lastDigit = tmp%10;
            tmp=tmp/10;
            if(st.empty())st.push(lastDigit);
            else if(lastDigit>=st.top())st.push(lastDigit);
            else{
                while(!st.empty() && lastDigit<st.top()){
                    justGreater = st.top();
                    st.pop();
                }
                break;
            }
            mp[lastDigit]++;
        }

        if(justGreater==0) return -1;

        mp[lastDigit]++;
        int flag = 1;
        int result = tmp*10+justGreater;

        for(auto [digit, count] : mp){
            while(count){
            if(digit==justGreater && flag){ 
                flag = 0;
                count--;
                continue;
            }
            if(result > ((INT_MAX-digit)/10)) return -1;    
            result = result*10+digit;
            count--;
            }
        }
        return result;
    }
};