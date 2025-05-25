////////////// Previous Smaller Element Problem //////////////////////

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// Function to find Previous Smaller Element for each element
vector<int> prevSmallerElement(vector<int> arr){
    stack<int> s;
    vector<int> ans(arr.size(), 0);

    for(int i=0; i<arr.size(); i++){
        // Pop all elements greater than or equal to current
        while(s.size() > 0 && s.top() >= arr[i]){
            s.pop();
        }

        if(s.empty()) {
            ans[i] = -1;
        }else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }
    return ans;
}

int main(){
    vector<int> arr = {3,1,0,8,6};

    vector<int> ans = prevSmallerElement(arr);

    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// For input {3, 1, 0, 8, 6}
//Output: -1 -1 -1 0 0

//T.C. : O[n]
//S.C. : O[n]