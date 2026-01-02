class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, rmax = 0, lmax=0, total = 0;
        while(left<right){
            lmax=max(lmax, height[left]);
            rmax=max(rmax, height[right]);
            if(height[left]<height[right]){
                int tmp = min(lmax, rmax) - height[left];
                if(tmp>0)total+=tmp;
                left++;
            }
            else{
                int tmp = min(lmax, rmax) - height[right];
                if(tmp>0) total+=tmp;
                right--;
            }
            
        }
        return total;
    }
};