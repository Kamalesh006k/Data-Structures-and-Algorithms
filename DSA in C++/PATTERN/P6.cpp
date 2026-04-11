#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k=1;
        for(int j=n-1;j>=i;j--)
        {
            cout<<k++<<" ";
        }
        cout<<endl;
    }
}