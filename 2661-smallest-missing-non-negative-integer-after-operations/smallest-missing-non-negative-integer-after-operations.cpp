class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int, int> m;

        for (int i = 0; i != nums.size(); i++) {
            int tmp = ((nums[i] % value) + value) % value;
            m[tmp]++;
        }

        for (int i = 0; i != nums.size()+1; i++) {
            int t = i % value;
            if (m[t]!=0) {
                m[t]--;
            } else
                return i;
        }
        return -1;
    }
};