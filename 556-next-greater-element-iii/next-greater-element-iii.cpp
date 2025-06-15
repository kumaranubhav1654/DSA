class Solution {
public:
    int nextGreaterElement(int n) {
        map<int, int>m;
        stack<int>st;
        int justGreater = 0, t = n, tmp = 0;
        while(t){
            tmp = t%10;
            t=t/10;
            if(st.empty())st.push(tmp);
            else if(tmp>=st.top())st.push(tmp);
            else{
                while(!st.empty() && tmp<st.top()){
                    justGreater = st.top();
                    st.pop();
                }
                break;
            }
            m[tmp]++;
        }

        if(justGreater==0) return -1;

        m[tmp]++;
        int flag = 1;
        t = t*10+justGreater;

        for(auto i : m){
            cout<<i.first<<endl;
            while(i.second){
            if(i.first==justGreater && flag){ 
                flag = 0;
                i.second--;
            }
            else{
            if(t>((INT_MAX-i.first)/10)) return -1;    
            t = t*10+i.first;
            i.second--;
            }
            }
        }
        return t;
    }
};