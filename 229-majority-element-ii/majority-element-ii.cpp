class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums;
        vector<int> ans;
        int len = nums.size();

        int majEle1 = nums[0], majEle2 = nums[0], count1 = 1, count2 = 0;

        for (int i = 1; i != len; i++) {
            if (nums[i] == majEle1)
                count1++;
            else if (nums[i] == majEle2) {
                majEle2 = nums[i];
                count2++;
            } else {
                if (count1 == 0) {
                    majEle1 = nums[i];
                    count1++;
                } else if (count2 == 0) {
                    majEle2 = nums[i];
                    count2++;
                } else {
                    count1--;
                    count2--;
                }
            }
        }

        cout<<majEle1<<". "<<majEle2;

        count1 = 0, count2 = 0;
        for (int i = 0; i != len; i++) {
            if (majEle1 == nums[i])
                count1++;
            if (majEle2 == nums[i])
                count2++;
        }
        if (majEle1 == majEle2 && count1 > len / 3)
            ans.push_back(majEle1);
        else {
            if (count1 > len / 3)
                ans.push_back(majEle1);
            if (count2 > len / 3)
                ans.push_back(majEle2);
        }

        return ans;
    }
};