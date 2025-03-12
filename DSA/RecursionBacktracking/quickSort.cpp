#include <iostream>
#include <vector>
using namespace std;

//function to make partitions sorted.
int partition(vector<int> &arr, int st, int end){ 
    int idx = st-1, pivot = arr[end];

    for(int j=st; j<end; j++){
        if(arr[j] <= pivot){  // (arr[j] >= pivot) ---->for decending
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    //for pivot correct position
    idx++;
    swap(arr[end], arr[idx]);
    return idx;
}

void quickSort(vector<int> &arr, int st, int end){ //divide the arr
    if(st < end){
        int pivIdx = partition(arr, st, end); 

        quickSort(arr, st, pivIdx-1);
        quickSort(arr, pivIdx+1, end);
    }
}

int main(){
    //vector<int> arr = {12, 31, 35, 8, 32, 17};
    vector<int> arr = {5, 2, 6, 4, 1, 3};
    quickSort(arr, 0, arr.size()-1);

    for(int val : arr){
        cout<< val<< " ";
    }
    cout << endl;
    return 0;
}