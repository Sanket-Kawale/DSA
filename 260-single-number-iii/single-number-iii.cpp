// using map
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        unordered_map<int, int>ans;

        for(int num : nums){
            ans[num]++;
        }

        int size = ans.size();
        for(auto num : ans){
            if(num.second == 1){
                result.push_back(num.first);
            }
        }
        return result;
    }
};