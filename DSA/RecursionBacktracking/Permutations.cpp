class Solution {
public:
        //ex-- [1,2,3]
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans){
        if(idx == nums.size()){ //Base-Case
            ans.push_back({nums});
            return;
        }

        for(int i=idx; i<nums.size(); i++){ //for, idx 0 1 2 ,it will run
            swap(nums[idx], nums[i]); //idx place => ith element choice, // Swap to choose the ith element
            getPerms(nums, idx+1, ans);// Recur for the next index.

            swap(nums[idx], nums[i]); //backtracking: Swap back to restore the original state.

            //We generate all possible permutations by swapping elements.
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums, 0, ans);

        return ans;
    }
};
