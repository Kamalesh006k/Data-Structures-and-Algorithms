#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sp=(n-1)*2;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout<<j+1;
        }
        for(int s=0;s<sp;s++)
        {
            cout<<" ";
        }
        int k=i+1;
        for(int j=0;j<=i;j++)
        {
            cout<<k--;
        }
         sp-=2;
        cout<<endl;
    }
    
}