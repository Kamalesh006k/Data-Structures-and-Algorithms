#include <bits/stdc++.h>
using namespace std;
int Count_all_subsequences(int n,vector<int>&res,int i,int t,int sum)
{
    if(sum==t)
    {
        return 1;
    }
    if(sum>t || i>=n)
    {
        return 0;
    }
    int left = Count_all_subsequences(n,res,i+1,t,sum+res[i]);
    int right = Count_all_subsequences(n,res,i+1,t,sum);
    return left+right;
}
int main()
{
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++)
    cin>>res[i];
    int k;
    cin>>k;
    cout<<Count_all_subsequences(n,res,0,k,0);
    
}