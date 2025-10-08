class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        int size = arr.size();
        for(int i=1; i<size; i++){
        int temp = arr[i];
        int j = i-1;
        while(j >= 0){
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
    }
    }
};