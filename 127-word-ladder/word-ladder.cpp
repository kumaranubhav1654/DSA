class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>>q;
        set<string>st;

        for(auto i : wordList) st.insert(i);

        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){
            auto [word, level] = q.front();
            q.pop();
            for(int j = 0; j!=word.size(); j++){
                string tmp = word;
                for(char k = 'a'; k<= 'z'; k++){
                    tmp[j] = k;
                    if(tmp == endWord && st.contains(tmp)) return level+1;
                    if(st.contains(tmp)){
                        q.push({tmp, level+1});
                        st.erase(tmp);
                    }
                }
            }
        }
        return 0;
    }
};