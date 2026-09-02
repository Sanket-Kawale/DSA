class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        vector<int> nums2(n, -1);
        bool odd = 0;
        bool even = 0;
        for(int i=0; i<n; i++){
            if(nums1[i] % 2 != 0){
                odd = 1;
                even = 0;
            }
            if(nums1[i] % 2 == 0){
                even = 1;
                odd = 0;
            }
        }

        if(odd == 1 && even == 0)   return true;
        if(even == 1 && odd == 0)   return true;

        return false;
    }
};