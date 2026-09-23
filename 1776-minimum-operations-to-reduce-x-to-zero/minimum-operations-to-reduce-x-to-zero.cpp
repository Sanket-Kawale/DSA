class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        if(target < 0) {
            return -1;
        }

        int left = 0, sum = 0, longest = -1;

        for(int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while(sum > target) {
                sum -= nums[left++];
            }

            if(sum == target) {
                longest = max(longest, right - left + 1);
            }
        }

        return longest == -1 ? -1 : nums.size() - longest;
    }
};