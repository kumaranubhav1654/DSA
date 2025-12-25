class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len==1) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int tmpStart = -1, maxEnd = INT_MIN;
        for(int i = 1; i!=intervals.size(); i++){
            if(intervals[i-1][1]<intervals[i][0] && intervals[i][0]>maxEnd){
                if(tmpStart==-1)ans.push_back(intervals[i-1]);
                else {
                    maxEnd = max(maxEnd, intervals[i-1][1]);
                    ans.push_back({tmpStart, maxEnd});
                    tmpStart = -1;
                }
            }
            else{
                if(tmpStart == -1) tmpStart = intervals[i-1][0];
                maxEnd = max(maxEnd, intervals[i-1][1]);
            }
        }
        maxEnd = max(maxEnd, intervals[len-1][1]);
        if(tmpStart==-1)ans.push_back(intervals[len-1]);
        else ans.push_back({tmpStart, maxEnd});
        return ans;
    }
};