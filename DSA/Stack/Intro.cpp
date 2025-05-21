///////////// Introduction To Stack //////////////


#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

////////// Implement using Vectors //////////
class Stack{
    vector<int> v;

public:

    void push(int val){//O[1]
        v.push_back(val);
    }

    void pop(){//O[1]
        v.pop_back();
    }
    
    int top(){//O[1]
        return v[v.size()-1];
    }

    bool empty(){
        return v.size() == 0;
    }
};

////////// Implement using Vectors //////////

class Stack1 {
    list<int> ll;

public:

    void push(int val){//O[1]
        ll.push_front(val);
    }

    void pop(){//O[1]
        ll.pop_front();
    }
    
    int top(){//O[1]
        return ll.front();
    }

    bool empty(){
        return ll.size() == 0;
    }

};

int main(){
    cout <<"Using vector : ";
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30); // 10 20 30
    
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl; //30 20 10

    cout <<"Using List class : ";
    Stack1 s1;

    s1.push(10);
    s1.push(20);
    s1.push(30); // 10 20 30
    
    while(!s1.empty()){
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl; //30 20 10

    cout <<"Using Stack STL "; //***simple way 
    stack<int> s3;
    s3.push(10);
    s3.push(20);
    s3.push(30); // 10 20 30
    
    while(!s3.empty()){
        cout << s3.top() << " ";
        s3.pop();
    }
    cout << endl; //30 20 10

    return 0;
}

