// You are using GCC
#include<bits/stdc++.h>
using namespace std;
// Maximum Possible Value
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    int sum=0,p=0,ne=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=abs(v[i]);
        if(v[i]<0 )
        {
            ne++;
        }
        else
        p++;
    }
    int small=INT_MAX;
    for(auto x : v)
    {
        if(abs(x)<small)
        small=abs(x);
    }
    if((p==0 && ne>0) || (p>0 && ne==0))
    {
        cout<<sum-(2*small);
    }
    else
    {
        cout<<sum;
    }
}