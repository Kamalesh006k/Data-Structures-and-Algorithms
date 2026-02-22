// You are using GCC
#include<bits/stdc++.h>
using namespace std;

int size1 = 0;

struct node
{
    int d;
    node *next;

    node(int val)
    {
        d = val;
        next = NULL;
    }
};

node *front = NULL, *rear = NULL;

// Enqueue
void push(int val)
{
    node *newnode = new node(val);

    if(front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }

    size1++;
}

// Front element
void frontelement()
{
    if(front == NULL)
    {
        cout << "Queue is Empty\n";
        return;
    }

    cout << front->d << endl;
}

// Dequeue
void pop()
{
    if(front == NULL)
    {
        cout << "Queue Underflow\n";
        return;
    }

    node* temp = front;
    front = front->next;

    if(front == NULL)   // If last element removed
        rear = NULL;

    delete temp;
    size1--;
}

// Size of queue
void sizeofQueue()
{
    cout << size1 << endl;
}

int main()
{
    push(2);
    push(10);
    push(12);

    cout << "Front Element: ";
    frontelement();

    cout << "Size: ";
    sizeofQueue();

    pop();

    cout << "Front Element after pop: ";
    frontelement();

    cout << "Size after pop: ";
    sizeofQueue();

    return 0;
}