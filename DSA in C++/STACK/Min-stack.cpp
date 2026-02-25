#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<pair<int,int>> st;

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) {
            st.push({val, val});
        } else {
            int mini = min(val, st.top().second);
            st.push({val, mini});
        }
        cout << val << " pushed\n";
    }
    
    void pop() {
        if(st.empty()) {
            cout << "Stack Underflow\n";
            return;
        }
        cout << st.top().first << " popped\n";
        st.pop();
    }
    
    int top() {
        if(st.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty()) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return st.top().second;
    }
};

int main() {

    MinStack obj;

    obj.push(5);
    obj.push(3);
    obj.push(7);
    obj.push(2);

    cout << "\nTop element: " << obj.top() << endl;
    cout << "Minimum element: " << obj.getMin() << endl;

    obj.pop();

    cout << "\nTop after pop: " << obj.top() << endl;
    cout << "Minimum after pop: " << obj.getMin() << endl;

    return 0;
}