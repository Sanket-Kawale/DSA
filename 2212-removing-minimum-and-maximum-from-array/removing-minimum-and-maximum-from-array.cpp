class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX;
        int mini_index = 0;
        int maxi = INT_MIN;
        int maxi_index = 0;
        int n = nums.size();

        // Find minimum and maximum indices
        for(int i = 0; i < n; i++) {
            if(nums[i] < mini) {
                mini = nums[i];
                mini_index = i;
            }

            if(nums[i] > maxi) {
                maxi = nums[i];
                maxi_index = i;
            }
        }

        int left = min(mini_index, maxi_index);
        int right = max(mini_index, maxi_index);

        // 3 possible ways:
        // 1. Remove both from left
        // 2. Remove both from right
        // 3. Remove one from each side
        return min({
            right + 1,
            n - left,
            left + 1 + n - right
        });
    }
};