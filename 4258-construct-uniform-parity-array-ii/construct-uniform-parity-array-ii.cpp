class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0, even = 0;

        for(int x : nums1) {
            if(x % 2)
                odd++;
            else
                even++;
        }

        // All already have same parity
        if(odd == 0 || even == 0)
            return true;

        // To make all odd, every even number needs a smaller odd number.
        int smallest = *min_element(nums1.begin(), nums1.end());

        if(smallest % 2 == 1)
            return true;

        // Smallest is even, so we cannot use an odd number smaller than
        // every even number. Hence mixed parity is impossible.
        return false;
    }
};