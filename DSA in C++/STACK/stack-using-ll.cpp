#include<bits/stdc++.h>
using namespace std;

int size = 0;

struct node
{
    node *next;
    int d;
    
    node(int d)
    {
        this->d = d;
        this->next = NULL;
    }
}*top = NULL;

void push(int val)
{
    node *newnode = new node(val);
    newnode->next = top;
    top = newnode;
    size++;
}

void topelement()
{
    if(top == NULL)
    {
        cout << "Stack is Empty\n";
        return;
    }
    cout << top->d << endl;
}

void pop()
{
    if(top == NULL)
    {
        cout << "Stack Underflow\n";
        return;
    }
    
    node* temp = top;
    top = top->next;
    delete temp;
    size--;
}

void sizeofStack()
{
    cout << size << endl;
}

int main()
{
    push(5);
    push(10);
    push(15);

    topelement();   // 15
    pop();
    topelement();   // 10
    sizeofStack();  // 2

    return 0;
}