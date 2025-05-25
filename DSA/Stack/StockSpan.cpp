//////////////////// Stock Span problem ///////////////
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int main(){
    //stock prices
    vector<int> price = {100, 80, 60, 70, 60, 75, 85};

    //solution
    vector<int> ans(price.size(), 0);
    stack<int> s;

    for(int i=0; i<price.size(); i++){ //n-times
        while(s.size() > 0 && price[s.top()] <= price[i]){
            s.pop();
        }

        if(s.empty()) {
            ans[i] = i+1;
        } else {
            ans[i] = i - s.top(); //i - prevHigh
        }

        s.push(i);
    }

    //print ans val
    for(int val : ans){
        cout << val << " ";
    }
    cout << endl;
    
    return 0;

}

//T.C: O[n],  S.C: O[n]--{stack}
// Output span:
//             1 1 1 2 1 4 6

//For each day, it calculates how many consecutive days (including today) the stock price was less than or equal to today's price.