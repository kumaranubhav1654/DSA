class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string>pow2;
        for(int i = 0; i!=31; i++){
            int t = pow(2, i);
            string tmp = to_string(t);
            sort(tmp.begin(), tmp.end());
            pow2.insert(tmp);
            //cout<<tmp<<endl;
        }
        string com = to_string(n);
        sort(com.begin(), com.end());
        //cout<<com<<endl;
        if(pow2.find(com)!=pow2.end()) return true;
        return false;
    }
};