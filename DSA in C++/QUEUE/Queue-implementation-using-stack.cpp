#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;

    MyQueue() {
        
    }
    
    void push(int x) {
        // Move all elements from st1 to st2
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        // Push new element into st1
        st1.push(x);

        // Move everything back to st1
        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        int temp = st1.top();
        st1.pop();
        return temp;
    }
    
    int peek() {
        return st1.top();
    }
    
    bool empty() {
        return st1.empty();
    }
};

int main() {

    MyQueue obj;

    obj.push(10);
    obj.push(20);
    obj.push(30);

    cout << "Front element: " << obj.peek() << endl;   // 10

    cout << "Popped element: " << obj.pop() << endl;   // 10

    cout << "Front element after pop: " << obj.peek() << endl; // 20

    cout << "Is queue empty? ";
    if(obj.empty())
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}