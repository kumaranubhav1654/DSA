class Solution {
public:
    int helper(string beginWord, string endWord, vector<string>& wordList,
               set<string> st, int ans) {
        queue<string> q;
        q.push(beginWord);

        while (!q.empty()) {
            int size = q.size();
            ans++;
            while (size--) {
                string tmp = q.front();
                q.pop();
                if (tmp == endWord)
                    return ans;
                for (int a = 0; a != tmp.length(); a++) {
                    char origional = tmp[a];
                    for (char i = 'a'; i <= 'z'; i++) {
                        tmp[a] = i;
                        if (st.find(tmp) != st.end()) {
                            q.push(tmp);
                            st.erase(tmp);
                        }
                    }
                    tmp[a] = origional;
                }
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        set<string> st;
        queue<string> q;

        for (auto i : wordList)
            st.insert(i);

        return helper(beginWord, endWord, wordList, st, 0);
    }
};