#include<iostream>
#include<vector>
using namespace std;

void printSubsets(vector<int> &arr, vector<int> &ans, int i){
    if(i==arr.size()){
        for(int val : ans){
            cout<<val<< "";
        }
        cout << endl;
        return;
    }

    //includes
    ans.push_back(arr[i]);
    printSubsets(arr,ans,i+1);

    ans.pop_back(); //backtracking
    
    //exclude
    printSubsets(arr,ans,i+1);
}

int main(){
    vector<int> arr = {1,2,3};//2^3= 8 (possible answers)
    vector<int> ans; //stores subsets
    
    printSubsets(arr, ans, 0);

    return 0;
}
