// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&s,int temp)
{
    if(s.empty())
    {
        s.push(temp);
        return ;
    }
    int val = s.top();
    s.pop();
    insertAtBottom(s,temp);
    s.push(val);
}

void reverse(stack<int>&s)
{
    if(s.empty())
    {
        return ;
    }
    
        int temp=s.top();
        s.pop();
        reverse(s);
        insertAtBottom(s,temp);
}
int main()
{
    int n;
    cin>>n;
    stack<int>s;
    for(int i=0;i<n;i++)
    {
        int el;
        cin>>el;
        s.push(el);
    }
     reverse(s);
    while (!s.empty())
    {
        /* code */
        cout<<s.top()<<" ";
        s.pop();
    }
    

}