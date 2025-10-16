class Solution {    //OPTIMAL SOLUTION
  public:           //using merge sort
    long long cnt = 0;

    void merge(vector<int>& arr, int s, int e) {
        int mid = s + (e - s) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        vector<int> left(len1);
        vector<int> right(len2);

        for (int i = 0; i < len1; i++)
            left[i] = arr[s + i];
        for (int i = 0; i < len2; i++)
            right[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = s;

        while (i < len1 && j < len2) {
            if (left[i] <= right[j]) {
                arr[k++] = left[i++];
            } else {
                arr[k++] = right[j++];
                cnt += (len1 - i); 
            }
        }

        while (i < len1) arr[k++] = left[i++];
        while (j < len2) arr[k++] = right[j++];
    }

    void mergeSort(vector<int>& arr, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, r);
    }

  public:
    long long inversionCount(vector<int>& arr) {
        cnt = 0; 
        mergeSort(arr, 0, arr.size() - 1);
        return cnt;
    }
};
