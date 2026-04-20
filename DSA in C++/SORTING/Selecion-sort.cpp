// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    
    for(int i=0;i<n-1;i++)
    {
        int temp=i;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[temp])
            {
                temp=j;
            }
        }
        swap(v[temp],v[i]);
        
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}