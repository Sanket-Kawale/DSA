class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n=arr.size();
        
        for(int i=0; i<n; i++){
            if(arr[i] < mini){
                mini = arr[i];
            }
        }
        
        for(int i=0; i<n; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
            }
        }
        
        return {mini, maxi};
    }
};