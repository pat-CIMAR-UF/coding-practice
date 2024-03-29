#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <stdio.h>
#include <string>
#include<algorithm>
#include <math.h>
#include <stack> 

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp_stack;
        while(!_data.empty()){
            temp_stack.push(_data.top());
            _data.pop();
        }
        
        temp_stack.push(x);
        
        while(!temp_stack.empty()){
            _data.push(temp_stack.top());
            temp_stack.pop();
        }
    
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = _data.top();
        _data.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        return _data.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return _data.empty();
    }
private:
    stack<int> _data;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */