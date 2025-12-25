class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m+n-1;
        if(m==0) nums1[0] = nums2[0];
        while(m!=0 && n!=0){
            int tmp = 0;
            if(nums1[m-1]<nums2[n-1]){
                nums1[end] = nums2[n-1];
                n--;
                end--;
            }
            else{
                nums1[end] = nums1[m-1];
                nums1[m-1] = 0;
                m--;
                end--;
            }
        }
        while(n!=0){
            nums1[n-1] = nums2[n-1];
            n--;
        }
    }
};