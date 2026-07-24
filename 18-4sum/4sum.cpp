class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        set<vector<int>> set;
        int n = nums.size();

        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int low = j+1;
                int high = n-1;

                long long newTarget = (long long)target-(nums[i]+nums[j]);

                while(low<high){
                    if(nums[low]+nums[high] < newTarget) low++;
                    else if(nums[low]+nums[high] > newTarget)    high--;
                    else{
                        set.insert({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                    }
                } 
            }
        }
        for(auto it:set){
            ans.push_back(it);
        }
        return ans;
    }
};