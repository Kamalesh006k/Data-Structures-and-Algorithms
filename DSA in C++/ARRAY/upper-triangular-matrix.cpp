// You are using GCC
#include<bits/stdc++.h>
// Upper Triangular Matrix
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>v[i][j];
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i<=j)
            sum+=v[i][j];
        }
    }
    cout<<sum;
}