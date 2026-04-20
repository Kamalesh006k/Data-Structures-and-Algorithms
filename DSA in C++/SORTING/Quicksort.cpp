// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>&v,int start,int end)
{
    
    int pivot=v[start];
    int i=start,j=end;
    while(i<j)
    {
        while(i<end && v[i]<=pivot)
        {
            i++;
        }
        while(j>=start && v[j]>pivot)
        {
            j--;
        }
        
        if(i<j)
        {
            swap(v[i],v[j]);
        }
    }
    
    swap(v[start],v[j]);
    return j;
    
}

void quicksort(vector<int>&v,int start,int end)
{
    if(start<end)
    {
    int pivot=partition(v,start,end);
    quicksort(v,start,pivot-1);
    quicksort(v,pivot+1,end);
    }
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
    quicksort(v,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}