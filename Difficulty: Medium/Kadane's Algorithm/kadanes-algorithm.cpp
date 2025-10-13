class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int n = arr.size();
        int target = INT_MIN;
        int temp = 0;
        for(int i=0; i<n; i++){
            temp = temp + arr[i];
            
            if(temp > target){
                target = temp;
            }
            if(temp < 0){
                temp = 0;
            }
        }
        return target;
    }
};