class Solution {
public:
    void solve(vector<int>& candidates, vector<int> temp, int index, int target, vector<vector<int>> &ans){

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(index == candidates.size()){
            return;
        }

        if(candidates[index] <= target){
            temp.push_back(candidates[index]);

            solve(candidates, temp, index, target-candidates[index], ans);
            temp.pop_back();
        }

        solve(candidates, temp, index+1, target ,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> temp;

        solve(candidates, temp, 0, target, ans);

        return ans;
    }
};