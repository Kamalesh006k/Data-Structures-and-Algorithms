// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int d=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n-1;j>=i;j--)
        {
            cout<<"*";
        }
        for(int s=0;s<d;s++)
        {
            cout<<" ";
        }
        for(int j=n-1;j>=i;j--)
        {
            cout<<"*";
        }
        d+=2;
        cout<<endl;
    }
    d=(n-1)*2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        for(int s=0;s<d;s++)
        {
            cout<<" ";
        }
        for(int j=0;j<=i;j++)
        {
            cout<<"*";
        }
        d-=2;
        cout<<endl;
    }
}
