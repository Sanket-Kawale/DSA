class Solution {
  public:
    void merge(vector<int>& arr, int l, int r){
        
        int mid = l + (r-l)/2;
        int len1 = mid+1 - l;
        int len2 = r - mid;
        
        int first[len1];
        int second[len2];
        
        int mainIndex = l;
        
        for(int i=0; i<len1; i++){
            first[i] = arr[mainIndex++];
        }
        mainIndex = mid+1;
        for(int i=0; i<len2; i++){
            second[i] = arr[mainIndex++];
        }
        
        int index1 = 0;
        int index2 = 0;
        
        mainIndex = l;
        
        while(index1 < len1 && index2 < len2){
            if(first[index1] < second[index2]){
                arr[mainIndex++] = first[index1++];
            }
            else{
                arr[mainIndex++] = second[index2++];
            }
        }
        while(index1 < len1){
            arr[mainIndex++] = first[index1++];
            
        }
        while(index1 < len1){
            arr[mainIndex++] = second[index2++];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        if(l >= r){
            return;
        }
        
        int mid = l + (r-l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, r);
    }
};