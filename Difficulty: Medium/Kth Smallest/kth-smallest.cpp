// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        for(int i=0; i<arr.size()-1; i++){
            for(int j=0; j<arr.size()-1; j++){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
        return arr[k-1];
        
        for(int i=0; i<k; i++){
            int  minIndex = i;
            for(int j=i+1; j<arr.size(); j++){
                if(arr[i] < arr[minIndex]){
                    minIndex = j;
                }
            }
            swap(arr[i], arr[minIndex]);
        }
        return arr[k-1];
    }
};