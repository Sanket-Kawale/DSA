class myStack {
  public:
    int top;
    int *arr;
    int n;
    myStack(int n) {
        top = -1;
        this->n = n;
        arr = new int[n];
    }

    bool isEmpty() {
        if(top == -1)   return 1;
        else    return 0;
    }

    bool isFull() {
        if(top == n-1)  return 1;
        else    return 0;
    }

    void push(int x) {
        if(!isFull()){
            top++;
            arr[top] = x;
        }
    }

    void pop() {
        if(!isEmpty()){
            top--;
        }
    }

    int peek() {
        if(top >= 0){
            return arr[top];
        }
    }
};