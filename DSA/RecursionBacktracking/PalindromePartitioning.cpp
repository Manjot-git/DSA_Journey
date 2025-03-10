//**************************** Palindrome Partitioning --problem no.131{leetcode} *****************************//

class Solution {
public:
    bool isPalin(string s){ //to check the part is palindrome or not.
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s == s2;  //true or false
    }


    void getAllPartitions(string s, vector<string> &partitions, vector<vector<string>> &ans){
        
        //Base-Case
        if(s.size() == 0){
            ans.push_back(partitions);
            return;
        }
        
        //recursion
        for(int i=0; i<s.size() ; i++){
            string part = s.substr(0, i+1);

            if(isPalin(part)){
                partitions.push_back(part);
                getAllPartitions(s.substr(i+1), partitions, ans);
                partitions.pop_back(); //backtracking
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;

        getAllPartitions(s, partitions, ans);
        return ans;
    }
};
