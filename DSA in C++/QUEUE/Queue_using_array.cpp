#include<bits/stdc++.h>
using namespace std;
//data
int n = 10;
int q[10];
int front = -1;
int rear = -1;

void push(int val)
{
    if(rear >= n - 1)
    {
        cout << "Queue Overflow\n";
        return;
    }

    if(front == -1)  // first element
        front = 0;

    rear++;
    q[rear] = val;
}

void pop()
{
    if(front == -1 || front > rear)
    {
        cout << "Queue Underflow\n";
        return;
    }

    front++;

    // Reset when queue becomes empty
    if(front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void frontelement()
{
    if(front == -1)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Front element: " << q[front] << endl;
}

void size()
{
    if(front == -1)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Size: " << rear - front + 1 << endl;
}

void display()
{
    if(front == -1)
    {
        cout << "Queue is empty\n";
        return;
    }

    cout << "Queue elements: ";
    for(int i = front; i <= rear; i++)
    {
        cout << q[i] << " ";
    }
    cout << endl;
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();
    frontelement();
    size();

    pop();
    display();
    size();

    return 0;
}
