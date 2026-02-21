#include<bits/stdc++.h>
using namespace std;

int n = 10;
int st[10];
int top = -1;

void push(int val)
{
    if(top >= n - 1)
    {
        cout << "Stack Overflow\n";
        return;
    }
    top++;
    st[top] = val;
}

void pop()
{
    if(top == -1)
    {
        cout << "Stack Underflow\n";
        return;
    }
    top--;
}

void topelement()
{
    if(top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Top element: " << st[top] << endl;
}

void size()
{
    cout << "Size: " << top + 1 << endl;
}

void display()
{
    if(top == -1)
    {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack elements: ";
    for(int i = top; i >= 0; i--)
    {
        cout << st[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();
    topelement();
    size();

    pop();
    display();
    size();

    return 0;
}