
class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n= q.size();
        int m= n/2;
        // if (n%2 != 0) return; 
        
        queue<int>firsthalf;

        for(int i=0;i<m;i++){
            firsthalf.push(q.front());
            q.pop();
        }
        
        while (!firsthalf.empty()) {
        q.push(firsthalf.front()); 
        firsthalf.pop();

        q.push(q.front());
        q.pop();
        
        }
    }
};