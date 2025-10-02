class Solution {
  public:
    void Rearrange(int arr[], int n) {
        rearrangeUtil(arr, 0, n - 1);
    }
    private:
    void rearrangeUtil(int arr[], int l, int r) {
        if (l >= r) return;

        int mid = (l + r) / 2;

        // Process left and right halves
        rearrangeUtil(arr, l, mid);
        rearrangeUtil(arr, mid + 1, r);

        // Merge step: put negatives before positives
        mergeBySign(arr, l, mid, r);
    }

    void mergeBySign(int arr[], int l, int mid, int r) {
        int i = l;

        // first positive index in left half
        while (i <= mid && arr[i] < 0) i++;

        int j = mid + 1;
        // first positive index in right half
        while (j <= r && arr[j] < 0) j++;

        // rotate [i..mid] with [mid+1..j-1]
        reverse(arr + i, arr + mid + 1);
        reverse(arr + mid + 1, arr + j);
        reverse(arr + i, arr + j);
    }
};