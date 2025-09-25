class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
       int mid = q.size()/2;
       queue<int> firsthalf;
       for(int i=0; i<mid; i++){
           int value = q.front();
           q.pop();
           firsthalf.push(value);
       }
       while(!firsthalf.empty()){
        q.push(firsthalf.front());
        firsthalf.pop();
        
        q.push(q.front());
        q.pop();
       }
    }
};