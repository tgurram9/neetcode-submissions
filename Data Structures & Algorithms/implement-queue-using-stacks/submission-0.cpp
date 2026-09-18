#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> pushStack;
    stack<int> popStack;
    
    MyQueue() {

    }
    
    void push(int x) {
        while (!popStack.empty()) {
            pushStack.push(popStack.top());
            popStack.pop();
        }
        pushStack.push(x);
    }
    
    int pop() {
        int val = peek();
        popStack.pop();
        return val;
    }
    
    int peek() {
        while(!pushStack.empty()) {
            popStack.push(pushStack.top());
            pushStack.pop();
        }

        return popStack.top();
    }
    
    bool empty() {
        return pushStack.empty() && popStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */