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

        bool swapped=false;
        for(int j=0;j<n-i-1;j++)
        {
            if(v[j]>v[j+1])
            {
            swap(v[j],v[j+1]);
            swapped=true;
            }
        
        }
        if(swapped==false)
        break;
        
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}