// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>&v,int start,int end,int mid)
{
    
    int i=start,j=mid,k=start;
    vector<int>t(v.size());
    while(i<mid && j<end)
    {
        if(v[i]<v[j])
        {
           t[k]=v[i];
           k++;
           i++;
        }
        else
        {
           t[k]=v[j];
           k++;
           j++;
        }
    }
    while(i<mid)
    {
        t[k]=v[i];
        i++;
        k++;
    }
    while(j<end)
    {
        t[k]=v[j];
        j++;
        k++;
    }
    for(int itr=start;itr<end;itr++)
    {
        v[itr]=t[itr];
    }
}

void mergesort(vector<int>&v,int start,int end)
{
    if(end-start==1)
    return ;
    
    int mid=(start+end)/2;
    mergesort(v,start,mid);
    mergesort(v,mid,end);
    merge(v,start,end,mid);
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    mergesort(v,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}