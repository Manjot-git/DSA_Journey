/////////////////////// Design A Min Stack Approach--1 /// P-155 ////////////////////

////////// S.C.: O[2n] /////////{used pair stack} 

class MinStack {
public:
// Stack stores pairs: (value, minimum_so_far)
    stack<pair<int,int>> s;//val, minVal

// Constructor initializes an empty stack
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        }else{
            int minVal = min(val,s.top().second);
            s.push({val,minVal});
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
