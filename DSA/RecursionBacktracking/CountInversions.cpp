//************Count Inversions problem--{basically of mergeSort type }***************//

#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &arr, int st, int mid, int end){
    vector<int> temp;
    int i = st, j =mid+1;
    int invCount = 0;

    while(i <= mid && j <= end){ //sorting
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        } else{
            temp.push_back(arr[j]);
            j++;

            invCount += (mid - i + 1);  // Inversions counted
        }
    }

    //remaining part we push in backward

    while(i <= mid){ //left
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end){ //right
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++){
        arr[st + idx] = temp[idx];
    }

    return invCount;
}

int mergeSort(vector<int> &arr, int st, int end){ // changes: void---to---int.
    if(st < end){ 
        int mid = st + (end-st)/2; 

        int leftInvCount = mergeSort(arr, st, mid); //left half
        int rightInvCount = mergeSort(arr, mid+1, end); //right half

        int invCount = merge(arr, st, mid, end);

        return leftInvCount + rightInvCount + invCount; 
    }

    return 0;
}

int main(){
    vector<int> arr = {12,31,35,8,32,17}; // ans 7
    //vector<int> arr = {6, 3, 5, 2, 7};  //ans 5

    int ans = mergeSort(arr, 0, arr.size()-1);

    cout << "Inversion Count of arr: " << ans << endl;

    
    return 0;
}
// Check the image here: "C:\Users\manjot\OneDrive\Pictures\Screenshots\Screenshot 2025-03-12 182938.png"
