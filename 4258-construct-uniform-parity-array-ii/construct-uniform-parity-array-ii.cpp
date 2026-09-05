class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0;
        int even = 0;

        for(int i=0; i<nums1.size(); i++){
            if(nums1[i] % 2 == 0){
                even++;
            }
            else{
                odd++;
            }
        }

        if(odd == 0 && even != 0)       return true;
        if(odd != 0 && even == 0)       return true;

        int smallest = *min_element(nums1.begin(), nums1.end());

        if(smallest % 2 == 1)   return true;

        return false;
    }
};