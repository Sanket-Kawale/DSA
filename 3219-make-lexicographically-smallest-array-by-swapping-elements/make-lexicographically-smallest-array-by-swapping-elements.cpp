class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> temp;
        int i=0;

        for(int i=0; i<n; i++){
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());

        while(i < n){
            int j = i;
            while(j+1 < n && temp[j+1].first - temp[j].first <= limit){
                j++;
            }

            vector<int> indices;
            vector<int> values;
            for(int k=i; k<=j; k++){
                indices.push_back(temp[k].second);
                values.push_back(temp[k].first);
            }
            sort(indices.begin(), indices.end());

            for(int k=0; k<values.size(); k++){
                nums[indices[k]] = values[k];
            }
            i = j+1;
        }
        return nums;
    }
};