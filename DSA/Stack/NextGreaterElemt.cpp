//////////////////// Next Greater Element problem ///////////////
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    vector<int> arr = {6,8,0,1,3};

//next greater elemt
    stack<int> s;
    vector<int> ans(arr.size(), 0);

    for(int i=arr.size()-1; i>=0; i--){
        while(s.size() > 0 && s.top() <= arr[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] = -1;
        } else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    //print the ans
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

//output: 8 -1 1 3 -1 

//S.C. : O[n]
//T.C. : O[n] --linear