class Solution {
  public:
    void merge(vector<int>& arr, int s, int e){
        int mid = (s+e)/2;
        int len1 = (mid+1) - s;
        int len2 = (e - mid);
        
        int first[len1];
        int second[len2];
        int mainIndex = s;
        
        for(int i=0; i<len1; i++){
            first[i] = arr[mainIndex++];
        }
        
        mainIndex = mid+1;
        for(int i=0; i<len2; i++){
            second[i] = arr[mainIndex++];
        }
        
        int index1 = 0;
        int index2 = 0;
        mainIndex = s;
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
        while(index2 < len2){
            arr[mainIndex++] = second[index2++];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        int mid = (l+r)/2;
        if(l >= r){
            return;
        }
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,r);
    }
};