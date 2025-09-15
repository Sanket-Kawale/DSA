class Solution {
  private:
    vector<int> nextSmallerElement(int *arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(int *arr, int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int *heights, int n) {
        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int area = 0;   // non-negative area
        for(int i=0; i<n; i++){
            int length = heights[i];
            if(next[i] == -1){
                next[i] = n;
            }
            int width = next[i] - prev[i] - 1;
            int newArea = length * width;
            area = max(area, newArea);
        }
        return area;
    }

  public:
    int maxArea(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        // first row
        int area = largestRectangleArea(mat[0].data(), m);
        
        // update rows
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] != 0)
                    mat[i][j] += mat[i-1][j];
                else  
                    mat[i][j] = 0;  
            }
            area = max(area, largestRectangleArea(mat[i].data(), m));
        }
        return area;
    }
};
