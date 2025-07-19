class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int size = nums.size();
        int num1 = nums[0], num2 = nums[0];
        int count1 = 1, count2 = 0;

        for(int i = 1; i!=size; i++){
            if(num1==nums[i])
                count1++;
            
            else if(num2==nums[i])
                count2++;
            
            else{
                if(count1==0) {
                    num1 = nums[i];
                    count1=1;
                }
                else if(count2==0){
                     num2 = nums[i];
                     count2=1;
                }
                else{
                    count1--;
                count2--;
                }
            }
        }
        count1=0, count2=0;
        for(int i = 0; i!=size; i++){
            if(num1==nums[i])count1++;
            else if(num2==nums[i])count2++;
        }
        vector<int> ans;
        if(count1>size/3) ans.push_back(num1);
        if(count2>size/3 && num1 != num2) ans.push_back(num2);
        return ans;
    }
};