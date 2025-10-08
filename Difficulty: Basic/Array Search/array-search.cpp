class Solution {
  public:
    int search(vector<int>& arr, int x) {
        int size = arr.size();
        int index;
        for(int i=0; i<size; i++){
            if(arr[i] == x){
                return i;
            }
        }
        return -1;
    }
};