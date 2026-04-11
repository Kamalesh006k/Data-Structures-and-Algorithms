#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int s=0;s<n-i-1;s++)
        {
            cout<<"  ";
        }
        char k='A';
        int mid=(2*i+1)/2;
        for(int j=0;j<2*i+1;j++)
        {
           cout<<k<<" ";

           if(j<mid)
           k++;
           else
           k--;
        }
        cout<<endl;
    }
}