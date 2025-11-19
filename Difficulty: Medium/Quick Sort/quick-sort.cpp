class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low >= high){
            return;
        }
        int p = partition(arr,low,high);
        
        
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        if(low >= high){
            return low;
        }
        int pivot = arr[low];
        int count = 0;
        for(int i=low+1; i<=high; i++){
            if(arr[i] <= pivot){
                count++;
            }
        }
        int pivotIndex = low+count;
        swap(arr[low], arr[pivotIndex]);
        
        int i = low; int j= high;
        
        while(i < pivotIndex && j>pivotIndex){
            while(arr[i] <= pivot){
                i++;
            }
            while(arr[j] > pivot){
                j--;
            }
            if(i < pivotIndex && j>pivotIndex){
                int temp = arr[i];
                arr[i++] = arr[j];
                arr[j--] = temp;
            }
        }
        return pivotIndex;
    }
};