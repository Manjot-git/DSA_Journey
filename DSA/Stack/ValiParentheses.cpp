class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for(int i=0; i<str.size(); i++){
            // If it's an opening bracket, push to stack
            if(str[i] == '(' || str[i] == '{' || str[i] == '['){
                st.push(str[i]);
            }else{// It's a closing bracket
                if(st.size() == 0){
                    return false;
                }

                // Check if top of stack matches current closing bracket
                if((st.top() == '(' && str[i] == ')') ||
                    (st.top() == '{' && str[i] == '}') ||
                    (st.top() == '[' && str[i] == ']')){

                        st.pop(); //match found so pop
                } else { //no match found
                    return false;
                }
            }
        }

        // If stack is empty, all brackets matched
        return st.size() == 0;
    }
};

 //Time Complexity:
//  O(n) — traverse each character once
