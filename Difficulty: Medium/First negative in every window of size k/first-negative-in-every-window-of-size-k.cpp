class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        deque<long long int> dq;
        vector<int> ans;
        int N = arr.size();
        int K = k;
        for(int i=0; i<K; i++){         //process first window of size k
            if(arr[i] < 0){
                dq.push_back(i);
            }
        }
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]); 
        }
        else{
            ans.push_back(0);
        }
        
        //process for remaining windows
        for(int i=K; i<N; i++){
            //removal
            if(!dq.empty() && i-dq.front() >= K){
                dq.pop_front();
            }
        //Addition
        if(arr[i] < 0){
            dq.push_back(i);
        }
        //answer store
        if(dq.size() > 0){
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
        return ans;
    }
};