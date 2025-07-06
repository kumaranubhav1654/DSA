class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 1;
        set<string>st;
        for(auto i : wordList) st.insert(i);
        queue<string>q;
        q.push(beginWord);

        while(!q.empty()){
            int s = q.size();
            while(s--){
                auto a = q.front();
                q.pop();
                string orig = a;
                if(a==endWord) return ans;
                for(int i = 0; i!=a.size(); i++){
                    char o = a[i];
                    for(char c = 'a'; c<='z'; c++){
                        a[i] = c;
                        if(st.find(a)!= st.end() && a!=orig){
                             q.push(a);
                             st.erase(a);
                        }
                    }
                    a[i] = o;
                }
            }
            ans++;
        }
        return 0;
    }
};