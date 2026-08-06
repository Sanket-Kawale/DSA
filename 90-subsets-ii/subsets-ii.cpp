class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int> nums, vector<int> output, int i){
        if(i == nums.size()){
            ans.push_back(output);
            return;
        }

        output.push_back(nums[i]);
        solve(ans, nums, output, i+1);
        output.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        solve(ans, nums, output, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;


        sort(nums.begin(), nums.end());
        solve(ans, nums, output, index);

        return ans;
    }
};