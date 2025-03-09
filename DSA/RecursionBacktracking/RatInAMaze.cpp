//Rat In A Maze problem.

#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &mat, int r,int c, string path ,vector<string> &ans/*   vector<vector<bool>> &vis */){

    int n = mat.size();
    if(r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1){//Base-Cases
        return;
    }

    if(r == n-1 && c == n-1) { //Base-case{main}
        ans.push_back(path); // Ans store
        return;
    }

    mat[r][c] = -1; // Mark as visited

    // helper(mat, r+1,c, path+"D", ans, vis); //down {before while using one more matrix but now we dont as we optimized it}

    helper(mat, r+1,c, path+"D", ans); //down
    helper(mat, r-1,c, path+"U", ans); //up
    helper(mat, r,c-1, path+"L", ans); //left
    helper(mat, r,c+1, path+"R", ans); //right

    mat[r][c] = 1; // Backtracking  //unvisited

}

//complete this function 
vector<string> findPath(vector<vector<int>> &mat) {
    int n =mat.size(); 

    vector<string> ans;
    string path = "";
    // vector<vector<bool>> vis(n, vector<bool>(n, false));

    helper(mat, 0, 0, path, ans/*  , vis   */);

    return ans;
}



int main() {
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };

    vector<string> ans = findPath(mat);
    for(string path : ans) {
        cout << path << endl;
    }

    return 0;
}
