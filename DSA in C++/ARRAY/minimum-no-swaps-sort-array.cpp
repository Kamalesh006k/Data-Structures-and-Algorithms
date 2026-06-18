// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++)
    {
        int el;
        cin>>el;
        v.push_back({el,i});
    }
    sort(v.begin(),v.end());
    int swap1=0;
    for(int i=0;i<n;i++)
    {
        if(i==v[i].second)
        {
            continue;
        }
        else
        {
            swap1++;
            swap(v[i],v[v[i].second]);
            i--;
        }
    }
    cout<<swap1;
}