#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        int n = q.size();
        q.push(x);

        for(int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

int main() {

    MyStack obj;

    obj.push(1);
    obj.push(2);
    obj.push(3);

    cout << "Top element: " << obj.top() << endl;   // 3

    cout << "Popped element: " << obj.pop() << endl; // 3

    cout << "Top element after pop: " << obj.top() << endl; // 2

    cout << "Is stack empty? ";
    if(obj.empty())
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}