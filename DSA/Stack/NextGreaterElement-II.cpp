//////////////////////  Next Greater Element II  P-503 //////////////////////

///////// Like Variation-1 but in "circular" form ////////

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);// Initialize answer vector with -1
        stack<int> s;


        // Loop from 2n - 1 to 0 to simulate circular array
        for(int i=2*n-1; i>=0; i--){  
            // Pop elements from the stack that are less than or equal to current element
            while(s.size() > 0 && nums[s.top()] <= nums[i%n]){
                s.pop();
            }

            ans[i%n] = s.empty() ? -1 : nums[s.top()];
            s.push(i%n);// Push current index into stack
        }
        
        return ans;
    }
};

//T.C---> O[n]
//S.C---> O[n]
