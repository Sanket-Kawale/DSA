class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> nums, vector<int> output, int index){

        if(index >= nums.size()){           //base condiiton reached
            ans.push_back(output);          //if out of bound index
            return;
        }

        //exclude number
        solve(ans, nums, output, index+1);  //right condition

        //include number                
        int element = nums[index];          //left condition
        output.push_back(element);
        solve(ans, nums, output, index+1);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;

        solve(ans, nums, output, index);

        return ans;
    }
};