class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int deficit = 0;            //required balance
        int balance = 0;            
        int start = 0;
        for(int i=0; i<gas.size(); i++){        //length of gas and cost vect is same
            balance += gas[i] - cost[i];        //finding balance
            if(balance < 0){                    //for negative balance
                deficit += balance;             //update deficit
                start = i+1;                    //update start to optimize space
                balance = 0;                    //update balance
            }
        }
        if(deficit + balance >= 0){             //cycle completed
            return start;
        }
        else{
            return -1;
        }
    }
};