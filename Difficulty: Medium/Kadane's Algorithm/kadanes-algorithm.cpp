class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSoFar = INT_MIN;
        int maxEndingHere = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            maxEndingHere += arr[i];
            
            if(maxEndingHere > maxSoFar){
                maxSoFar = maxEndingHere;
            }
            
            if(maxEndingHere < 0){
                maxEndingHere = 0;
            }
        }
        return maxSoFar;
    }
};