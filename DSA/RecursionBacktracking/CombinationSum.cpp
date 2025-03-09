//**************************COMBINATION SUM PROBLEM*********************************//

class Solution {
public:
    set<vector<int>> s;  // to handle multiple same answer we use this.
 
    void getAllCombinations(vector<int>& arr,int idx,  int tar, vector<vector<int>> &ans, vector<int> &combin ){
        //Base-Cases:
        if(tar == 0){
            if(s.find(combin) == s.end()){
                ans.push_back(combin); // Store valid combination
                s.insert(combin);
            }
            
            return ;
        }

        if(idx == arr.size() || tar < 0){
            return; // Stop if we reach the end or target becomes negative.
        }


        combin.push_back(arr[idx]);

        //single // Include current element (Single occurrence)
        getAllCombinations(arr, idx+1, tar-arr[idx], ans, combin);
        //multiple  // Multiple occurrences allowed
        getAllCombinations(arr, idx, tar-arr[idx], ans, combin);

        combin.pop_back(); //backtrack

        //exclusion // Exclude current element
        getAllCombinations(arr, idx+1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllCombinations(arr, 0, target, ans, combin);

        return ans;
    }
};
