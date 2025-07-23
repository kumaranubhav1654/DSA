// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//         stack<char> st;
//         int ans=0, ans2=0;
//         for(int i = 0; i!=s.length(); i++){
//             if(st.empty() && (s[i]!='b' && s[i]!='a')) continue;
//             else if(st.empty() && (s[i]=='b' || s[i]=='a'))st.push(s[i]);
//             else if(s[i]=='b' && st.top()=='a'){
//                 st.pop();
//                 ans+=x;
//             }
//             else if(s[i]=='b' || s[i]=='a')
//                 st.push(s[i]);
//             else{
//                 int t = 0;
//                 while(!st.empty()){
//                     st.pop();
//                     t++;
//                 }
//                 ans+=y*(t/2);
//             }
//         }
//         stack<char> st2;
//         for(int i = 0; i!=s.length(); i++){
//             if(st2.empty() && (s[i]!='a' && s[i]!='b')) continue;
//             else if(st2.empty() && (s[i]=='a' || s[i]=='b'))st2.push(s[i]);
//             else if(s[i]=='a' && st2.top()=='b'){
//                 st2.pop();
//                 ans2+=y;
//             }
//             else if(s[i]=='a' || s[i]=='b')
//                 st2.push(s[i]);
//             else{
//                 int t = 0;
//                 while(!st2.empty()){
//                     st2.pop();
//                     t++;
//                 }
//                 ans2+=x*(t/2);
//             }
//         }
//         return max(ans2,ans);
//     }
// };


class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        char ch1 = 'a', ch2 = 'b';
        int cnt1 = 0, cnt2 = 0;

        if (x < y) {
            swap(x, y);
            ch1 = 'b';
            ch2 = 'a';
        }

        for (char ch : s) {
            if (ch == ch1) {
                cnt1++;
            } else if (ch == ch2) {
                if (cnt1 > 0) {
                    cnt1--;
                    score += x;
                } else {
                    cnt2++;
                }
            } else {
                score += min(cnt1, cnt2) * y;
                cnt1 = 0;
                cnt2 = 0;
            }
        }

        if (cnt1 != 0) {
            score += min(cnt1, cnt2) * y;
        }

        return score;
    }
};