class Solution {
  public:
    queue<int> reverse(queue<int> &q, stack<int> st){
        while(!q.empty()){
            int element = q.front();
            st.push(element);
            q.pop();
        }
        while(!st.empty()){
            int value = st.top();
            q.push(value);
            st.pop();
        }
    return q;
    }
    void reverseQueue(queue<int> &q) {
        stack<int> st;
        reverse(q,st);
    }
};