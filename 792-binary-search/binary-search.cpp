class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start)/2;  //for range out of bounds

        while(start <= end){
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                start++;
            }
            else{
                end--;
            }
            mid = start + (end - start)/2;
        }
        return -1;
    }
};