class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int i = 0; // Tracks content children
        int j = 0; // Tracks cookie availability
        
        while (i < g.size() && j < s.size()) {
            // If the cookie satisfies the child, move to the next child
            if (s[j] >= g[i]) {
                i++;
            }
            // Regardless of a match, this cookie is processed; look at the next one
            j++;
        }
        return i; 
    }
};
