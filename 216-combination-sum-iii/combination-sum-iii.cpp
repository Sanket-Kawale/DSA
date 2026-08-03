class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &temp, int k, int target, int start){
        int sum = 0;

        if(k < 0 || target < 0){
            return;         //invalid cases
        }

        if(k == 0 && target == 0){
            ans.push_back(temp);
            return;         //condition reached
        }

        for(int i=start; i<=9; i++){
            if(i > target)      break;  //error

            temp.push_back(i);
            solve(ans, temp, k-1, target-i, i+1);
            temp.pop_back();
            //decr k, update target and index
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        solve(ans, temp, k, n, 1);
        return ans;
    }
};