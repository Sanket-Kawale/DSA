class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int n = nums.size()-1;
        vector<int> s_mini(n+1);
        s_mini[n] = nums[n];

        for(int i=n-1; i>=0; i--){
            s_mini[i] = min(nums[i], s_mini[i+1]);
        }

        for(int i=0; i<=n; i++){
            maxi = max(maxi, nums[i]);
            mini = s_mini[i];

            int dummy = maxi - mini;
            if(dummy <= k){
                return i;
            }
        }
        return -1;
    }
};