class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        set<int>st;
        int fk = 0;
        for(auto i: nums){
            if(i==k) fk++;
            st.insert(i);
        }

        int maxCount = 0;

        for(auto i : st){
            int count = 0;
            for(auto num : nums){
                if(num==k) count--;
                if(num==i)count++;
                if(count < 0) count = 0;
                maxCount=max(maxCount, count);
            }
        }
        return fk+maxCount;
    }
};