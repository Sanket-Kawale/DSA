class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>&candidates, int target, vector<int> &temp, int index){
        int n = candidates.size();
        if(target == 0){
            ans.push_back(temp);
            return;
        }
    
        for(int i=index; i<n; i++){
            if(i>index && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > target)      break;

            temp.push_back(candidates[i]);

            solve(ans, candidates, target-candidates[i], temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        int n = candidates.size();

        sort(candidates.begin(), candidates.end());

        solve(ans, candidates, target, temp, 0);

        return ans;
    }
};