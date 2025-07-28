class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans = 0;
        bool up, down = false;
        int tmp = nums[0];

        for(int i = 1; i!=nums.size(); i++){
            if(tmp==nums[i]) continue;
            else if (tmp < nums[i]){
                if(down){
                    ans++;
                    down = false;
                    up = true;
                }
                up = true; 
            }
            else{
                if(up){
                    ans++;
                    up = false;
                    down = true;
                }
                down = true; 
            }
            tmp = nums[i];
        }
        return ans;
    }
};