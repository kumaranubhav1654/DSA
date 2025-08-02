class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int, greater<int>>mp1;
        map<int, int> mp2, mp3;
        int gmin = INT_MAX;
        long long ans = 0;

        for(int i = 0; i!=basket1.size(); i++ ){
            mp1[basket1[i]]++;
            mp2[basket2[i]]++;
            mp3[basket1[i]]++;
            mp3[basket2[i]]++;
            gmin = min(gmin, min(basket2[i], basket1[i]));
        }

        for(auto itr = mp3.begin(); itr!=mp3.end(); itr++){
            if(itr->second%2!=0)return -1;
            else if(mp1[itr->first]==mp2[itr->first]){
                mp1.erase(itr->first);
                mp2.erase(itr->first);
            }
            else{
                if(mp1[itr->first]<mp2[itr->first]){
                    mp2[itr->first]= (mp2[itr->first] - mp1[itr->first])/2;
                    mp1.erase(itr->first);
                }
                else{
                    mp1[itr->first] = (mp1[itr->first] - mp2[itr->first])/2;
                    mp2.erase(itr->first);
                }
            }
        }

        auto itr1 = mp1.begin(), itr2 = mp2.begin();

        while(itr1!=mp1.end() && itr2!=mp2.end()){
            ans += min(2*gmin, min(itr1->first, itr2->first));
            itr1->second--;
            itr2->second--;
            if(itr1->second==0){
                mp1.erase(itr1->first);
                itr1++;
            }
            if(itr2->second==0){
                mp2.erase(itr2->first);
                itr2++;
            }
        }
        return ans;
    }
};