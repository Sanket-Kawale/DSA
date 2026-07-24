class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int count = nums[0];
        int temp = 0;
        
        for(int i=0; i<n; i++){
            temp = temp+nums[i];

            if(temp > count)        count = temp;
            if(temp < 0)   temp = 0;
        }
        return count;
    }
};