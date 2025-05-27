/////////////////// Design a Min Stack Approach--2  P-155 ///////////////////

                           /////////  S.C--O[n]  ////////

class MinStack {
public:
    stack<long long int> s; //overflow se bachne ke liye used "long long int"
    long long int minVal;

    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            // If stack is empty, push the value directly and set minVal
            s.push(val);
            minVal = val;
        }else{
            if(val < minVal){
                // Encode the new minimum value to maintain the previous min
                s.push((long long) 2*val - minVal);
                minVal = val;
            } else{
                // Push normally if val is not a new min
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.top() < minVal){
            // If the top is an encoded value, decode previous min
            minVal = 2*minVal - s.top();
        }

        s.pop();// Pop the top element
    }
    
    int top() {
        if(s.top() < minVal){ // If encoded, return current min
            return minVal;
        }else{
            return s.top();// Otherwise return actual top
        }
    }
    
    int getMin() {
        return minVal;// Return the current minimum value
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
