// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char d='A'+n-1;
    for(int i=0;i<n;i++)
    {
            char t=d;
        for(int j=0;j<=i;j++)
        {
            cout<<t++<<" ";
        }
        d--;
        cout<<endl;
    }
}