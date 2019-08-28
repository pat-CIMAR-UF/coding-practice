#include <iostream>
#include <stack>

using namespace std;


class minstack{
public:
    
    stack<int> _data;
    stack<int> _min;
    
    minstack(){}
    
    void push(int x){
        _data.push(x); //push the data into stack
        
        if (_min.empty()){
            _min.push(x);    
        } // if the min is empty, push the data directly
        
        else{
            if (x > _min.top()){
                x = _min.top();
            }
            _min.push(x);
        } // compare current data with the min, choose the smaller one into the min stack
    }
    
    int pop(){
        
        int pop_num = _data.top();
        _data.pop();
        _min.pop();
        
         return pop_num;
    }
    
    int peek(){
        return _data.top();
    }
    
    int peekMin(){
        return _min.top();
    }
    

};

int main(){
    minstack MS;
    MS.push(-2);
    cout << MS.peek() << endl;
    cout << MS.peekMin() << endl;
    
    MS.push(0);
    
    MS.push(-5);
    /*
    cout << MS.peek();
    cout << MS.peekMin();
    */
    
    cout << MS.peek() << endl;
    cout << MS.peekMin() << endl;
    cout << MS.pop() << endl;
    
    return 0;
}