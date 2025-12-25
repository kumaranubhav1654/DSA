class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m+n-1;
        int i = m-1, j = n-1;
        while(i!=-1 && j!=-1){
            if(nums1[i]<nums2[j]){
                nums1[end--] = nums2[j--];
            }
            else{
                nums1[end--] = nums1[i--];
            }
        }
        while(j!=-1){
            nums1[end--] = nums2[j--];
        }
    }
};