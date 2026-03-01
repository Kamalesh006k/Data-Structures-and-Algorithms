// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int d;
    node* next;
    node(int d)
    {
        this->d=d;
        this->next=NULL;
    }
}*head=NULL,*pos=NULL,*newnode=NULL;
void insert(int d)
{
    newnode=new node(d);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        pos=head;
        while(pos->next!=head)
        {
            pos=pos->next;
        }
        pos->next=newnode;
        newnode->next=head;
    }
}
void sortnode()
{
    
    for(pos=head;pos->next!=head;pos=pos->next)
    {
        for(node *pos1=pos->next;pos1!=head;pos1=pos1->next)
        {
            if(pos->d>pos1->d)
            swap(pos->d,pos1->d);
        }
    }
}
void display()
{
    pos=head;
    cout<<pos->d<<" ";
    pos=pos->next;
    while(pos!=head)
    {
        cout<<pos->d<<" ";
        pos=pos->next;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int el;
        cin>>el;
        insert(el);
    }
    sortnode();
    display();
}
