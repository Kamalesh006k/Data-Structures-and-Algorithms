#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        flag=true;
        else
        flag=false;
        for(int j=0;j<=i;j++)
        {
            if(flag)
            cout<<1<<" ";
            else
            cout<<0<<" ";
            flag=!flag;
        }
        cout<<endl;
    }
}