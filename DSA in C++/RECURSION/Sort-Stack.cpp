// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void insertsort(stack<int>&s,int temp)
{
    if(s.empty() || s.top()<=temp)
    {
        s.push(temp);
        return ;
    }
    int val = s.top();
    s.pop();
    insertsort(s,temp);
    s.push(val);
}

void stacksort(stack<int>&s)
{
    if(!s.empty())
    {
        int temp=s.top();
        s.pop();
        stacksort(s);
        insertsort(s,temp);
    }
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
     stacksort(s);
    while (!s.empty())
    {
        /* code */
        cout<<s.top()<<" ";
        s.pop();
    }
    

}